#ifndef MAP_TS_HPP_
#define MAP_TS_HPP_

/*
Спроектировать и реализовать потокобезопасный мап со следующими свойствами:
- Ключем и значением является строка.
- Потоки могут получать эксклюзивный доступ к записям в мапе.
- Только поток получивший эксклюзивный доступ к записи может менять её
значение.
- Один поток может получить эксклюзивный доступ к нескольким записям.
- Если потоку нужно обратиться к записи, которая в эксклюзивном доступе
у другого потока, то он должен ждать пока запись освободится.
- Если запрашивается доступ к записи, которой нет в мапе, то создается
и возвращается новая запись.

При решении допускается использование только чистого c++11.
 */

#include <string>
#include <map>
#include <vector>
#include <mutex>
#include <utility>
#include <memory>
#include <iostream>

using namespace std;

class Map_TS
{
	// == METHODS ==
public:
    explicit Map_TS() {}
    ~Map_TS();

    Map_TS(const Map_TS& other) = delete;
    Map_TS(Map_TS&& other) = delete;
    Map_TS& operator=(const Map_TS& other) = delete;
    Map_TS& operator=(Map_TS&& other) = delete;

    string at(const string& key);
    void clear();
    void erase(const string& key);
    bool insert(const string& key, const string& value);
    bool isEmpty() const;
    vector<string> keys() const;
    void replace(const string& key, const string& value);
    size_t size() const;

    // == DATA ==
private:
    class Node
    {
    public:
        Node(const string& str) : mtx(new mutex()), value(str) {}

        Node(const Node& other)
        {
            mtx = std::move(other.mtx);
            value = other.value;
        }

        //Node(const Node& other) = delete;
        Node(Node&& other) = delete;
        Node& operator=(const Node& other) = delete;
        Node& operator=(Node&& other) = delete;

        unique_ptr<mutex> mtx;
        string value;
    };

    map<string, Node> m_map;
};

Map_TS::~Map_TS()
{
    clear();
}

string Map_TS::at(const string& key)
{
    map<string, Node>::iterator iter = m_map.find(key);
    if (iter != m_map.end())
    {
        unique_lock<mutex> lck(*(iter->second.mtx));
        return iter->second.value;
    }

    insert(key, string());
    return string();

}

void Map_TS::clear()
{
    vector<string> mapKeys = this->keys();
    for (const string& str : mapKeys)
    {
        erase(str);
    }
}

void Map_TS::erase(const string& key)
{
    map<string, Node>::iterator iter = m_map.find(key);
    if (iter != m_map.end())
    {
        unique_lock<mutex> lck(*(iter->second.mtx));
        iter->second.value = string();
    }

    m_map.erase(key);
}

bool Map_TS::insert(const string& key, const string& value)
{
    if (m_map.find(key) != m_map.end())
    {
        return false;
    }

    pair<string, Node> element(key, Node(value));
    return m_map.insert(element).second;
}

bool Map_TS::isEmpty() const
{
    return m_map.empty();
}

vector<string> Map_TS::keys() const
{
    vector<string> mapKeys;
    for (map<string, Node>::const_iterator iter = m_map.cbegin();
            iter != m_map.cend(); ++iter)
    {
        mapKeys.push_back(iter->first);
    }

    return mapKeys;
}

void Map_TS::replace(const string& key, const string& value)
{
    map<string, Node>::iterator iter = m_map.find(key);
    if (iter != m_map.end())
    {
        unique_lock<mutex> lck(*(iter->second.mtx));
        iter->second.value = value;
    }
}

size_t Map_TS::size() const
{
    return m_map.size();
}

#endif /* MAP_TS_HPP_ */
