#include "..\Public\GameObjectHandle.h"
#include "Game\Public\GameObjectInventory.h"

GameObjectHandle::GameObjectHandle()
	: mHash(0)
{
}

GameObjectHandle::GameObjectHandle(std::size_t pHash)
{
	mHash = pHash;
}

bool GameObjectHandle::IsValid()
{
	return GameObjectInventory::Instance()->Exists(mHash);
}

GameObject* GameObjectHandle::Get()
{
	return GameObjectInventory::Instance()->Lookup(mHash);
}
