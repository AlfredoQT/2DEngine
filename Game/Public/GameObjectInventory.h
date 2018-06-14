#pragma once

#include "Engine\Public\Core\Containers\HashMap.h"
#include "Singleton.h"

class GameObject;

// Provides access to game objects in a hash map
class GameObjectInventory : public Singleton<GameObjectInventory>
{
public:

	void Register(GameObject* pGO);

	void UnRegister(GameObject* pGO);

	bool Exists(std::size_t pHash);

	GameObject* Lookup(std::size_t pHash);

private:

	// So its a hashmap with keys as unsigned int which will refer to the hash of the game object
	HashMap<std::size_t, GameObject*, 256> mMap;
};
