#ifndef TYPE_MAP_HPP_
#define TYPE_MAP_HPP_

#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <functional>

// http://www.cplusplus.com/reference/map/map/
// Maps are associative containers that store elements formed by a combination
// of a key value and a mapped value, following a specific order.
//
// In a map, the key values are generally used to sort and uniquely identify
// the elements, while the mapped values store the content associated to
// this key. The types of key and mapped value may differ, and are grouped
// together in member type value_type, which is a pair type combining both:
// typedef pair<const Key, T> value_type;
//
// Internally, the elements in a map are always sorted by its key following
// a specific strict weak ordering criterion indicated by its internal
// comparison object (of type Compare).
//
// map containers are generally slower than unordered_map containers to
// access individual elements by their key, but they allow the direct
// iteration on subsets based on their order.
//
// The mapped values in a map can be accessed directly by their corresponding
// key using the bracket operator ((operator[]).
//
// Maps are typically implemented as binary search trees.
//
// Container properties:
// - Associative
//   Elements in associative containers are referenced by their key and not by
//   their absolute position in the container.
//
// - Ordered
//   The elements in the container follow a strict order at all times. All
//   inserted elements are given a position in this order.
//
// - Map
//   Each element associates a key to a mapped value: Keys are meant to
//   identify the elements whose main content is the mapped value.
//
// - Unique keys
//   No two elements in the container can have equivalent keys.
//
// - Allocator-aware
//   The container uses an allocator object to dynamically handle its storage
//   needs.
//
// Template parameters:
// - Key
//   Type of the keys. Each element in a map is uniquely identified by its key
//   value. Aliased as member type map::key_type.
//
// - T
//   Type of the mapped value. Each element in a map stores some data as its
//   mapped value. Aliased as member type map::mapped_type.
//
// - Compare
//   A binary predicate that takes two element keys as arguments and returns
//   a bool. The expression comp(a,b), where comp is an object of this type
//   and a and b are key values, shall return true if a is considered to go
//   before b in the strict weak ordering the function defines.
//   The map object uses this expression to determine both the order the
//   elements follow in the container and whether two element keys are
//   equivalent (by comparing them reflexively: they are equivalent
//   if !comp(a,b) && !comp(b,a)). No two elements in a map container can have
//   equivalent keys.
//   This can be a function pointer or a function object (see constructor for
//   an example). This defaults to less<T>, which returns the same as applying
//   the less-than operator (a<b).
//   Aliased as member type map::key_compare.
//
// - Alloc
//   Type of the allocator object used to define the storage allocation model.
//   By default, the allocator class template is used, which defines the
//   simplest memory allocation model and is value-independent.
//   Aliased as member type map::allocator_type.

void Creation()
{
    std::map<int, char> map1;
    std::map<int, std::string> map2;
    std::map<std::string, int> map3;

    std::map<int, char> map4 = {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};
    std::cout << "Size of the map4: " << map4.size() << std::endl;
}

void WorkWithContainer()
{
    std::map<int, int> myMap;
    myMap[1] = 11;
    myMap.insert( std::pair<int, int>(2, 22) );
    myMap.insert({3, 33});

    std::cout << "Size of the myMap: " << myMap.size() << std::endl;
    std::cout << "Do myMap contains key 2: " << myMap.count(2) << std::endl;

    myMap.erase(3);
    myMap.erase(4);
    std::cout << "Size of the myMap after elements erasure: " <<
            myMap.size() << std::endl;

    myMap.clear();
}

void OrderOfElements()
{
    std::cout << std::endl << "OrderOfElements in std::map" << std::endl;
    std::map<int, int> mapAsc;
    std::map<int, int, std::greater<int>> mapDesc;

    mapAsc.insert({2, 20});
    mapAsc.insert(std::pair<int, int>(1, 10));
    mapAsc[8] = 80;

    mapDesc.insert({2, 20});
    mapDesc.insert(std::pair<int, int>(1, 10));
    mapDesc[8] = 80;

    std::cout << "Map with elements sorted in ascending order:" << std::endl;
    for (std::map<int, int>::iterator it = mapAsc.begin();
            it != mapAsc.end();
            ++it)
    {
        std::cout << it->first << " - " << it->second << std::endl;
    }

    std::cout << "Map with elements sorted in descending order:" << std::endl;
    for (const std::pair<int, int>& i : mapDesc)
    {
        std::cout << i.first << " - " << i.second << std::endl;
    }
}

void StartMap()
{
    Creation();
    WorkWithContainer();
    OrderOfElements();
}

#endif /* TYPE_MAP_HPP_ */
