#include "..\Public\TestGame.h"
#include "Engine\Public\Engine.h"
#include "Engine\Public\Core\Types\Color.h"
#include "Engine\Public\Core\Types\Vector2.h"

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
	mEngine->DrawFillCircle(Vector2(400.0f, 300.0f), 600.0f, Color(50, 70, 245, 40), 2);
}

void TestGame::End()
{
}
