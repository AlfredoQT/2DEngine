#pragma once

template<class T>
class Singleton
{

protected:

	Singleton() {}

	// Store the singleton
	static T* mSingleton;

public:

	// Disallow copy constructor
	Singleton(const Singleton& copy) = delete;

	// Disallow copy assignment operator
	Singleton& operator=(const Singleton& copy) = delete;

	// Allow access to the singleton
	static T* Instance()
	{
		// Create the singleton
		if (mSingleton == nullptr)
		{
			mSingleton = new T();
		}
		return mSingleton;
	}

	// Provides functionality for deleting the singleton from heap
	static void DestroyInstance()
	{
		delete mSingleton;
		mSingleton = nullptr;
	}
};
