#ifndef CONCURRENTMAP_HPP_
#define CONCURRENTMAP_HPP_

#include <string>
#include <map>
#include <vector>
#include <mutex>
#include <memory>
#include <iostream>

using namespace std;

namespace DS {

class ConcurrentMap
{
    // == DATA ==
private:
    class Node
    {
    public:
        Node(const string& str) : mtx(new mutex()), value(str) {}

        unique_ptr<mutex> mtx;
        string value;
    };

    map<string, Node> m_map;
    recursive_mutex m_mutex;

    // == METHODS ==
public:
    explicit ConcurrentMap() {}
    ~ConcurrentMap();

    ConcurrentMap(const ConcurrentMap& other) = delete;
    ConcurrentMap(ConcurrentMap&& other) = delete;
    ConcurrentMap& operator=(const ConcurrentMap& other) = delete;
    ConcurrentMap& operator=(ConcurrentMap&& other) = delete;

    string at(const string& key) const;
    void clear();
    bool contains(const string& key) const;
    void erase(const string& key);
    bool insert(const string& key, const string& value);
    bool isEmpty() const;
    vector<string> keys() const;
    void set(const string& key, const string& value);
    size_t size() const;

private:
    void erase(map<string, Node>::iterator iter);
};

ConcurrentMap::~ConcurrentMap()
{
    clear();
}

// Get mapped value of the element identified with the key.
// @input:
// - key - string with key
// @output:
// - string - value that is mapped with the key. If map doesn't contain such
// key, function will return empty string.
string ConcurrentMap::at(const string& key) const
{
    map<string, Node>::const_iterator iter = m_map.find(key);
    if (iter != m_map.cend())
    {
        return iter->second.value;
    }

    return string();
}

// Remove all elements form the map
void ConcurrentMap::clear()
{
    lock_guard<recursive_mutex> mapLock(m_mutex);
    while(false == m_map.empty())
    {
        erase(m_map.begin());
    }
}

// Check if map contains requested key
// @input:
// - key - string with key
// @output:
// - bool - True if map contains such key, otherwise False
bool ConcurrentMap::contains(const string& key) const
{
    return m_map.find(key) != m_map.end();
}

// Erase key-value pair from the map
// @input:
// - key - string with key
void ConcurrentMap::erase(const string& key)
{
    map<string, Node>::iterator iter = m_map.find(key);
    erase(iter);
}

// Erase key-value pair from the map
// @input:
// - iter - valid iterator to the map element
void ConcurrentMap::erase(map<string, Node>::iterator iter)
{
    if (iter == m_map.end())
    {
        return;
    }

    {
        lock_guard<mutex> lck(*(iter->second.mtx));
    }

    lock_guard<recursive_mutex> mapLock(m_mutex);
    m_map.erase(iter);

}

// Insert key-value pair to the map
// @input:
// - key - string with key
// - value - string with value
// @output:
// - bool - True if key-value pair was inserted to the map, otherwise False.
// Also function may return False if map already contains such key.
bool ConcurrentMap::insert(const string& key, const string& value)
{
    if (m_map.find(key) != m_map.end())
    {
        return false;
    }

    bool result = false;
    {
        lock_guard<recursive_mutex> lock(m_mutex);
        result = m_map.emplace(key, Node(value)).second;
    }

    return result;
}

// Check if map is empty
// @output:
// - bool - True if map is empty, otherwise False.
bool ConcurrentMap::isEmpty() const
{
    return m_map.empty();
}

// Get list of all keys in the map
// @output:
// - vector<string> - container with keys
vector<string> ConcurrentMap::keys() const
{
    vector<string> mapKeys;
    for (map<string, Node>::const_iterator iter = m_map.cbegin();
            iter != m_map.cend(); ++iter)
    {
        mapKeys.push_back(iter->first);
    }

    return mapKeys;
}

// Set value for specified key
// If map doesn't contain such key-value pair, this pair will be inserted
// to the map
// @input:
// - key - string with key
// - value - string with value
void ConcurrentMap::set(const string& key, const string& value)
{
    map<string, Node>::iterator iter = m_map.find(key);
    if (iter != m_map.end() && iter->second.value != value)
    {
        lock_guard<mutex> lck(*(iter->second.mtx));
        iter->second.value = value;
    }
    else
    {
        insert(key, value);
    }
}

// Get number of elements in the map
// @output:
// - size_t - number of elements in the map
size_t ConcurrentMap::size() const
{
    return m_map.size();
}

}

#endif /* CONCURRENTMAP_HPP_ */
