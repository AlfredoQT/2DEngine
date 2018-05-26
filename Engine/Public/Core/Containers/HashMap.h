#pragma once

#include "SymbolTable.h"
#include <functional>

// Got the idea from a Quora answer for the list that stores key and value pairs in its nodes
// from https://www.quora.com/What-is-a-map-data-structure-How-does-it-store-data
// The API for the implementation of the SymbolTable from Robert Sedgewick's Algorithm's Book 4th edition
// The code is written by me
// I used size_t to prevent integer overflow with std::hash
template<class K, class T, std::size_t SIZE>
class HashMap
{
public:

	HashMap()
	{
		// SIZE is a power of 2
		mMask = SIZE - 1;
	}

	void Put(K pKey, T pValue)
	{
		// Get the hash
		std::size_t index = hash(pKey);
		// Access the bucket and insert the value, it already does the checking
		mBuckets[index].Put(pKey, pValue);
	}

	T Get(K pKey)
	{
		// Hash the key
		std::size_t index = hash(pKey);
		// Get the value for that key in that bucket
		return mBuckets[index].Get(pKey);
	}

	void Remove(K pKey)
	{
		// Hash the key
		std::size_t index = hash(pKey);
		// Delete the key in that symbol table
		mBuckets[index].Remove(pKey);
	}

	bool Contains(K pKey)
	{
		// Just look it up
		return Get(pKey) != 0;
	}

private:

	// Returns a value between 0 and SIZE-1
	std::size_t hash(K pKey)
	{
		// Hash the key
		std::size_t hash = std::hash<K>{} (pKey);
		return hash & mMask;
	}

	std::size_t mMask;

	// Buckets
	SymbolTable<K, T> mBuckets[SIZE];

};
