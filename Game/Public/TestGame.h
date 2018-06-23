#pragma once

#include "IGame.h"

class Engine;

class TestGame : public IGame
{
public:

	TestGame();

	void Init(Engine* pEngine) override;
	void Run() override;
	void End() override;

private:

	Engine* mEngine;

};