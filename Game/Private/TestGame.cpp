#include "..\Public\TestGame.h"
#include "Engine\Public\Engine.h"

TestGame::TestGame()
	: mEngine(nullptr)
{
}

void TestGame::Init(Engine * pEngine)
{
	mEngine = pEngine;
}

void TestGame::Run()
{
	// Some tests to the engine interface
}

void TestGame::End()
{
}
