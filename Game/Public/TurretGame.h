#pragma once

#include "IGame.h"

class Engine;
class World;

class TurretGame : public IGame
{
public:

	TurretGame();

	void Init(Engine* pEngine) override;
	void Run() override;
	void End() override;

private:

	World* mWorld;

};
