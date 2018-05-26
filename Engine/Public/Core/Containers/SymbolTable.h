#pragma once

// The node for the symbol table
template<class K, class T>
class Node
{
public:

	Node<K, T>* mNext;
	K mKey;
	T mValue;

	Node(Node<K, T>* pNext, K pKey, T pValue)
	{
		mNext = pNext;
		mKey = pKey;
		mValue = pValue;
	}
};

// This class is basically a linked list that holds key, value pairs, keys being unique
template<class K, class T>
class SymbolTable
{
private:

	// Start point of the linked list
	Node<K, T>* mHead;

	int mSize;

public:

	SymbolTable()
	{
		mHead = nullptr;
		mSize = 0;
	}

	~SymbolTable()
	{

	}

	// Get a value from the linked list given a key
	T Get(K pKey)
	{
		Node<K, T>* current = mHead;
		while (current != nullptr)
		{
			// Check for the key
			if (current->mKey == pKey)
			{
				return current->mValue;
			}
			// Move
			current = current->mNext;
		}
		// Not found
		return 0;
	}

	// Insert something at the linked list, if the key already exists, update its value
	void Put(K pKey, T pValue)
	{
		Node<K, T>* current = mHead;
		// Look for an existing key
		while (current != nullptr)
		{
			if (current->mKey == pKey)
			{
				// Update the value
				current->mValue = pValue;
				return;
			}
			// Move
			current = current->mNext;
		}
		// Looks like we've found no existing key
		Node<K, T>* oldHead = mHead;
		// Just add it to the back
		mHead = new Node<K, T>(oldHead, pKey, pValue);
		++mSize;
	}

	// Returns true if the key is present
	bool Remove(K pKey)
	{
		Node<K, T>* previousToDelete = nullptr;
		Node<K, T>* toDelete = mHead;
		while (toDelete != nullptr)
		{
			// Found
			if (toDelete->mKey == pKey)
			{
				// Found in the head
				if (previousToDelete == nullptr)
				{
					// Move the head
					mHead = toDelete->mNext;
					delete toDelete;
					--mSize;
					return true;
				}
				// Do normal removal
				previousToDelete->mNext = toDelete->mNext;
				delete toDelete;
				--mSize;
				return true;
			}
			// Move both
			previousToDelete = toDelete;
			toDelete = toDelete->mNext;
		}
		// Not found
		return false;
	}

	// Just the size
	int GetSize() const
	{
		return mSize;
	}

};
