#include "..\Public\GameObjectInventory.h"
#include "Game\Public\GameObject.h"

GameObjectInventory* Singleton<GameObjectInventory>::mSingleton = nullptr;

void GameObjectInventory::Register(GameObject * pGO)
{
	mMap.Put(pGO->GetHash(), pGO);
}

void GameObjectInventory::UnRegister(GameObject * pGO)
{
	mMap.Remove(pGO->GetHash());
}

bool GameObjectInventory::Exists(std::size_t pHash)
{
	return mMap.Contains(pHash);
}

GameObject* GameObjectInventory::Lookup(std::size_t pHash)
{
	return mMap.Get(pHash);
}
