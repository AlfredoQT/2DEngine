#pragma once

#include <vector>
#include <algorithm>

class GameObject;

// our base component class
class Component
{
public:

	Component(GameObject* pGO);

	virtual void Initialize();
	virtual void Destroy();

	GameObject* GetGO() const;

protected:

	// I get it as a reference and push back onto it
	template<class T>
	void AddToComponentVector(std::vector<T*>& componentVector)
	{
		componentVector.push_back((T*)this);
	}

	template<class T>
	void RemoveFromComponentVector(std::vector<T*>& componentVector)
	{
		componentVector.erase(std::remove(componentVector.begin(), componentVector.end(), this), componentVector.end());
	}

protected:

	GameObject * mGO;

};
