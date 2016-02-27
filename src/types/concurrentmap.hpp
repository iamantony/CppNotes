#ifndef CONCURRENTMAP_HPP_
#define CONCURRENTMAP_HPP_

// Author: Antony Cherepanov

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
#include <memory>
#include <iostream>

using namespace std;

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
    mutex m_mutex;

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

string ConcurrentMap::at(const string& key) const
{
    map<string, Node>::const_iterator iter = m_map.find(key);
    if (iter != m_map.cend())
    {
        return iter->second.value;
    }

    return string();
}

void ConcurrentMap::clear()
{
    lock_guard<mutex> mapLock(m_mutex);
    for (map<string, Node>::iterator iter = m_map.begin();
            iter != m_map.end();
            ++iter)
    {
        erase(iter);
    }
}

void ConcurrentMap::erase(const string& key)
{
    map<string, Node>::iterator iter = m_map.find(key);
    erase(iter);
}

void ConcurrentMap::erase(map<string, Node>::iterator iter)
{
    if (iter == m_map.end())
    {
        return;
    }

    {
        unique_lock<mutex> lck(*(iter->second.mtx));
    }

    m_map.erase(iter);
}

bool ConcurrentMap::insert(const string& key, const string& value)
{
    if (m_map.find(key) != m_map.end())
    {
        return false;
    }

    bool result = false;
    {
        lock_guard<mutex> lock(m_mutex);
        result = m_map.emplace(key, Node(value)).second;
    }

    return result;
}

bool ConcurrentMap::isEmpty() const
{
    return m_map.empty();
}

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

void ConcurrentMap::set(const string& key, const string& value)
{
    map<string, Node>::iterator iter = m_map.find(key);
    if (iter != m_map.end())
    {
        lock_guard<mutex> lck(*(iter->second.mtx));
        iter->second.value = value;
    }
}

size_t ConcurrentMap::size() const
{
    return m_map.size();
}

#endif /* CONCURRENTMAP_HPP_ */
