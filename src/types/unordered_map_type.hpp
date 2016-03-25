#ifndef UNORDERED_MAP_TYPE_HPP_
#define UNORDERED_MAP_TYPE_HPP_

#include <unordered_map>
#include <utility>
#include <string>
#include <iostream>
#include <functional>

// http://www.cplusplus.com/reference/unordered_map/unordered_map/
// Unordered maps are associative containers that store elements formed by the
// combination of a key value and a mapped value, and which allows for fast
// retrieval of individual elements based on their keys.
//
// In an unordered_map, the key value is generally used to uniquely identify
// the element, while the mapped value is an object with the content associated
// to this key. Types of key and mapped value may differ.
//
// Internally, the elements in the unordered_map are not sorted in any
// particular order with respect to either their key or mapped values, but
// organized into buckets depending on their hash values to allow for fast
// access to individual elements directly by their key values (with a constant
// average time complexity on average).
//
// unordered_map containers are faster than map containers to access individual
// elements by their key, although they are generally less efficient for
// range iteration through a subset of their elements.
//
// Unordered maps implement the direct access operator (operator[])
// which allows for direct access of the mapped value using its key value
// as argument.
//
//Iterators in the container are at least forward iterators.
//
// Container properties^
// - Associative
//   Elements in associative containers are referenced by their key and not by
//   their absolute position in the container.
//
// - Unordered
//   Unordered containers organize their elements using hash tables that allow
//   for fast access to elements by their key.
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
//   Type of the key values. Each element in an unordered_map is uniquely
//   identified by its key value.
//   Aliased as member type unordered_map::key_type.

// - T
//   Type of the mapped value. Each element in an unordered_map is used to
//   store some data as its mapped value.
//   Aliased as member type unordered_map::mapped_type. Note that this is not
//   the same as unordered_map::value_type.
//
// - Hash
//   A unary function object type that takes an object of type key type as
//   argument and returns a unique value of type size_t based on it. This can
//   either be a class implementing a function call operator or a pointer to a
//   function (see constructor for an example). This defaults to hash<Key>,
//   which returns a hash value with a probability of collision approaching
//   1.0/std::numeric_limits<size_t>::max().
//   The unordered_map object uses the hash values returned by this function
//   to organize its elements internally, speeding up the process of locating
//   individual elements.
//   Aliased as member type unordered_map::hasher.
//
// - Pred
//   A binary predicate that takes two arguments of the key type and returns
//   a bool. The expression pred(a,b), where pred is an object of this type
//   and a and b are key values, shall return true if a is to be considered
//   equivalent to b. This can either be a class implementing a function call
//   operator or a pointer to a function (see constructor for an example).
//   This defaults to equal_to<Key>, which returns the same as applying the
//   equal-to operator (a==b).
//   The unordered_map object uses this expression to determine whether two
//   element keys are equivalent. No two elements in an unordered_map container
//   can have keys that yield true using this predicate.
//   Aliased as member type unordered_map::key_equal.
//
// - Alloc
//   Type of the allocator object used to define the storage allocation model.
//   By default, the allocator class template is used, which defines the
//   simplest memory allocation model and is value-independent.
//   Aliased as member type unordered_map::allocator_type.

//How is a hash table implemented?
// A hash table is traditionally implemented with an array of linked lists.
// When we want to insert a key/value pair, we map the key to an index in the
// array using a hash function.
//
// The value is then inserted into the linked list at that position.
// Note that the elements in a linked list at a particular index of the array
// do not have the same key. Rather, hashFunction (key) is the same for
// thesevalues.Therefore, in order to retrieve the value for a specific key, we
// need to store in each node both the exact key and the value.
//
// To summarize,the hash table will be implemented with an array of linked
// lists, where each node in the linked list holds two pieces of data:
// the value and the original key. In addition, we will want to note the
// following design criteria:
//
// 1. We want to use a good hash function to ensure that the keys are well
// distributed. If they are not well distributed, then we would get a lot of
// collisions and the speed to find an element would decline.
//
// 2. No matter how good our hash function is,we will still have collisions,
// so we need a method for handling them. This often means chaining via a
// linked list, but it's not the only way.
//
// 3. We may also wish to implement methods to dynamically increase or
// decrease the hash table size depending on capacity. For example, when the
// ratio of the number of elements to the table size exceeds a certain
// threshold, we may wish to increase the hash table size. This would mean
// creating a new hash table and transferring the entries from the old table
// to the new table. Because this is an expensive operation, we want to be
// careful to not do it too often.

void Creation()
{
    std::unordered_map<int, char> map1;
    std::unordered_map<int, std::string> map2;
    std::unordered_map<std::string, int> map3;

    std::unordered_map<int, char> map4 =
       {{1, 'a'}, {3, 'b'}, {5, 'c'}, {7, 'd'}};
    std::cout << "Size of the map4: " << map4.size() << std::endl;
}

void WorkWithContainer()
{
    std::unordered_map<int, int> myMap;
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
    std::cout << std::endl << "OrderOfElements in std::unordered_map" <<
            std::endl;

    std::unordered_map<int, int> myMap;
    myMap.insert({2, 20});
    myMap.insert(std::pair<int, int>(1, 10));
    myMap[8] = 80;

    std::cout << "Elements in the map:" << std::endl;
    for (const std::pair<int, int>& i : myMap)
    {
        std::cout << i.first << " - " << i.second << std::endl;
    }
}

void StartUnorderedMap()
{
    Creation();
    WorkWithContainer();
    OrderOfElements();
}

#endif /* UNORDERED_MAP_TYPE_HPP_ */
