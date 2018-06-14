#include "..\Public\GameObject.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObjectInventory.h"
#include "Game\Public\GameObjectHandle.h"

GameObject::GameObject(World* pWorld, std::size_t pHash)
{
	mWorld = pWorld;
	mHash = pHash;

	mTag = "";

	GameObjectInventory::Instance()->Register(this);
}

GameObject::~GameObject()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Destroy();

		delete pComponent;
		pComponent = nullptr;
	}
	
	GameObjectInventory::Instance()->UnRegister(this);
}

void GameObject::Initialize()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Initialize();
	}
}

void GameObject::AddComponent(Component * pComponent)
{
	mComponents.push_back(pComponent);
}

World * GameObject::GetWorld() const
{
	return mWorld;
}

std::size_t GameObject::GetHash()
{
	return mHash;
}

GameObjectHandle GameObject::GetHandle() const
{
	return GameObjectHandle(mHash);
}

std::string GameObject::GetTag() const
{
	return mTag;
}

void GameObject::SetTag(const std::string& pTag)
{
	mTag = pTag;
}

std::vector<Component*> GameObject::GetComponents() const
{
	return mComponents;
}
