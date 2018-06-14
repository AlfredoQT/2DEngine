#pragma once
#include <vector>

class COGGameManager;
class GameObjectHandle;
class Engine;

// the world, it contains all of our game objects and defines the order of updates
class World
{
public:

	World(Engine* pEngine);

	void Destroy();

	void Update();

	void Add(GameObjectHandle pHandle);

	void Delete(GameObjectHandle pHandle);

	void FreeMemory();

	std::vector<GameObjectHandle> GetHandles();

	Engine* GetEngine() const;

	void SetGameManager(COGGameManager* pGameManager);

private:

	std::vector<GameObjectHandle> mHandles;
	std::vector<GameObjectHandle> mHandlesToDelete;

	Engine* mEngine;

	COGGameManager* mGameManager;

};