// dp6.h
// Kelby Hubbard, Rose Peters, and Yali Wang
// Started: 2020-10-30
// Updated: 2020-10-30

// For CS 311 Fall 2020
// Header for Project 6 functions


// CREDIT:
//
//
//

#ifndef FILE_DP6_H_INCLUDED
#define FILE_DP6_H_INCLUDED

#include "llnode2.h"	
#include <memory>		// for std::unique_ptr
#include <functional>

// reverseList
// Efficient reversing function for a Linked List of LLNode2
// Pre:
//	Valid LLNode2 unique pointer
// ??? Guarantee
template<typename ValType>
void reverseList(std::unique_ptr<LLNode2<ValType>>& head)
{
	std::unique_ptr<LLNode2<ValType>> newHead(nullptr);
	std::unique_ptr<LLNode2<ValType>> currentHead(nullptr);

	while (head != nullptr)
	{
		currentHead = head->_next;
		head->_next = newHead;
		newHead = head;
		head = currentHead;
	}

	head = newHead;
}

// **********************************************************************
// class LLMap - Class definition
// **********************************************************************
// class LLMap
// Templated linked list map
// Invariants:
//		???
// Type requirements:
//		???
template <typename Key, typename Data>
class LLMap {

	// ***** LLMap: Types *****
public:
	// key_type: type of key items
	using key_type = Key;
	// data_type: type of data items
	using data_type = Data;

	// ***** LLMap: Constructors, Destructors *****
public:
	// Default constructor
	// Creates an empty data set
	// ??? Guarantee
	LLMap() : _head(nullptr)
	{}

	// Default destructor
	// No Throw Guarantee
	~LLMap()
	{}

	// Big 5: 
	// LLMap must not have any other public member functions
	// Copy ctor, move ctor, copy assignment op, and move assignment op deleted
	LLMap(const LLMap& other) = delete;
	LLMap(LLMap&& other) = delete;
	LLMap& operator=(const LLMap& other) = delete;
	LLMap& operator=(const LLMap&& other) = delete;

	// ***** LLMap: Public Member Functions *****
public:
	// size
	// Returns an integer of appropriate type 
	// giving the number of key-value pairs in LLMap
	/// ??? Guarantee
	int size() const
	{

	}

	// empty
	// Returns a bool indicating if there are no key-balue pairs in LLMap
	// ??? Guarantee
	bool empty() const
	{

	}

	// find
	// Returns a const pointer to value of the key given if the 
	// key is in LLMap, otherwise returns nullptr
	// Pre:
	//		
	// ??? Guarantee
	const data_type* find(key_type key) const
	{

	}

	// insert
	// If the key does not lie in LLMap then the key-value pair is inserted
	// If key already lies in LLMap, overwrite with given key-value pair
	// Pre:
	//		
	// ??? Guarantee
	void insert(key_type key, data_type data)
	{

	}

	// erase
	// If key is found then erase the key-value pair
	// If key isn't found do nothing
	// Pre:
	//		
	// ??? Guarantee
	void erase(key_type key)
	{

	}

	// traverse
	// Applies a function to every object in LLMap
	// Pre:
	//		
	// ??? Guarantee
	void traverse(std::function<void(key_type, data_type)>) const
	{

	}

	// ***** LLMap: Data Members *****
private:
	std::unique_ptr<LLNode2<std::pair<key_type, data_type>>> _head;

}; // End class LLMap

#endif // FILE_DP6_H_INCLUDED