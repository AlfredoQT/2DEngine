#pragma once

#include "..\Public\COG\Component.h"
#include <vector>
#include <typeinfo>
#include <string>

class World;
class GameObjectHandle;

// our game object, it's just a collection of components - that's it!
class GameObject
{
public:
	
	GameObject(World* pWorld, std::size_t pHash);

	~GameObject();

	void Initialize();

	void AddComponent(Component* pComponent);

	template<class T>
	T* FindComponent()
	{
		int i = 0;
		for (Component* pComponent : mComponents)
		{
			if (typeid(T).hash_code() == typeid(*pComponent).hash_code())
			{
				return (T*)pComponent;
			}
			++i;
		}

		return nullptr;
	}

	World* GetWorld() const;

	std::size_t GetHash();

	GameObjectHandle GetHandle() const;

	std::string GetTag() const;

	void SetTag(const std::string& pTag);

	std::vector<Component*> GetComponents() const;

private:
	std::vector<Component*> mComponents;

	World* mWorld;

	std::size_t mHash;

	std::string mTag;

};
