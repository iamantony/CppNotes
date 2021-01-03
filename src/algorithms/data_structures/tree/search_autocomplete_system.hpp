#ifndef CPPNOTESMAIN_SEARCH_AUTOCOMPLETE_SYSTEM_HPP
#define CPPNOTESMAIN_SEARCH_AUTOCOMPLETE_SYSTEM_HPP

/*
https://leetcode.com/problems/design-search-autocomplete-system/
Design a search autocomplete system for a search engine. Users may input a sentence (at least one
word and end with a special character '#'). For each character they type except '#', you need to
return the top 3 historical hot sentences that have prefix the same as the part of sentence
already typed. Here are the specific rules:

1. The hot degree for a sentence is defined as the number of times a user typed the exactly same
sentence before.
2. The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one).
If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one
appears first).
3. If less than 3 hot sentences exist, then just return as many as you can.
4. When the input is a special character, it means the sentence ends, and in this case, you need
to return an empty list.

Your job is to implement the following functions:

The constructor function:

AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is
historical data. Sentences is a string array consists of previously typed sentences. Times is the
corresponding times a sentence has been typed. Your system should record these historical data.

Now, the user wants to input a new sentence. The following function will provide the next
character the user types:

List<String> input(char c): The input c is the next character typed by the user. The character
will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#').
Also, the previously typed sentence should be recorded in your system. The output will be the
top 3 historical hot sentences that have prefix the same as the part of sentence already typed.


Example:
Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2])
The system have already tracked down the following sentences and their corresponding times:
"i love you" : 5 times
"island" : 3 times
"ironman" : 2 times
"i love leetcode" : 2 times
Now, the user begins another search:

Operation: input('i')
Output: ["i love you", "island","i love leetcode"]
Explanation:
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have
same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should
be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be
ignored.

Operation: input(' ')
Output: ["i love you","i love leetcode"]
Explanation:
There are only two sentences that have prefix "i ".

Operation: input('a')
Output: []
Explanation:
There are no sentences that have prefix "i a".

Operation: input('#')
Output: []
Explanation:
The user finished the input, the sentence "i a" should be saved as a historical sentence in system.
And the following input will be counted as a new search.

Note:
* The input sentence will always start with a letter and end with '#', and only one blank space
will exist between two words.
* The number of complete sentences that to be searched won't exceed 100. The length of each
sentence including those in the historical data won't exceed 100.
* Please use double-quote instead of single-quote when you write test cases even for a character
input.
* Please remember to RESET your class variables declared in class AutocompleteSystem, as
static/class variables are persisted across multiple test cases. Please see here for more details.
*/

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

namespace Algo::DS::Tree {
    class SearchAutoCompleteSystem {
        const char sentence_end = '#';
        const size_t top_size = 3;

        struct PTNode {
            std::vector<size_t> sentences;
            std::unordered_map<char, PTNode*> children;

            PTNode() = default;
            ~PTNode() {
                for (auto iter = children.begin(); iter != children.end(); ++iter) {
                    delete iter->second;
                }
            }
        };

        PTNode m_prefix_tree;
        PTNode* m_current_node = nullptr;
        std::string m_current_sentence;
        std::vector<std::pair<std::string, int>> m_data;

        void insert_sentence(const size_t sentence_pos) {
            const auto& sentence = m_data.at(sentence_pos).first;
            PTNode* cur = &m_prefix_tree;
            for (const auto& c : sentence) {
                auto iter = cur->children.find(c);
                if (iter == cur->children.end()) {
                    auto [new_iter, _] = cur->children.insert({c, new PTNode()});
                    iter = new_iter;
                }

                cur = iter->second;
                cur->sentences.push_back(sentence_pos);
            }
        }

        void update_top_of_nodes(PTNode* n) {
            if (n == nullptr) { return; }

            sort_sentences(n->sentences);
            for (auto& [ch, cn] : n->children) {
                update_top_of_nodes(cn);
            }
        }

        void sort_sentences(std::vector<size_t>& sentences) {
            auto begin = sentences.begin();
            auto end = sentences.end();
            auto middle = end;
            if (sentences.size() > top_size) {
                middle = begin;
                std::advance(middle, top_size);
            }

            std::partial_sort(
                begin,
                middle,
                end,
                [this](const auto& left, const auto& right){
                    const auto& lsp = m_data.at(left);
                    const auto& rsp = m_data.at(right);
                    return lsp.second != rsp.second ?
                        lsp.second > rsp.second : lsp.first < rsp.first;
                });
        }

        void process_current_sentence() {
            auto iter = std::find_if(
                m_data.begin(),
                m_data.end(),
                [this](const auto& s) { return s.first == m_current_sentence; });

            if (iter != m_data.end()) {
                ++iter->second;
            }
            else {
                m_data.push_back({m_current_sentence, 1});
                insert_sentence(m_data.size() - 1);
            }

            update_top_of_nodes(&m_prefix_tree);

            m_current_sentence.clear();
            m_current_node = &m_prefix_tree;
        }

    public:
        SearchAutoCompleteSystem(
            const std::vector<std::string>& sentences, const std::vector<int>& times)
        {
            for (size_t i = 0; i < sentences.size(); ++i) {
                m_data.push_back({sentences[i], times[i]});
            }

            for (size_t i = 0; i < m_data.size(); ++i) {
                insert_sentence(i);
            }

            update_top_of_nodes(&m_prefix_tree);
            m_current_node = &m_prefix_tree;
        }

        std::vector<std::string> input(char c) {
            if (c == sentence_end) {
                process_current_sentence();
                return {};
            }

            m_current_sentence += c;
            auto iter = m_current_node->children.find(c);
            if (iter == m_current_node->children.end()) {
                auto [new_iter, _] = m_current_node->children.insert({c, new PTNode()});
                iter = new_iter;
            }

            m_current_node = iter->second;
            std::vector<std::string> top;
            const auto max_pos = std::min(m_current_node->sentences.size(), top_size);
            for (size_t i = 0; i < max_pos; ++i) {
                top.push_back(m_data.at(m_current_node->sentences.at(i)).first);
            }

            return top;
        }
    };
}

#endif //CPPNOTESMAIN_SEARCH_AUTOCOMPLETE_SYSTEM_HPP
