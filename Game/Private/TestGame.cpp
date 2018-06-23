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
	mEngine->DrawFillCircle(Vector2(400.0f, 300.0f), 600.0f, Color(50, 70, 245), 2);
	mEngine->DrawRect(Vector2(400.0f, 300.0f), Vector2(790.0f, 590.0f), Color(70, 248, 120), 1);
	mEngine->DrawLine(Vector2(10.0f, 10.0f), Vector2(790.0f, 590.0f), Color(255, 0, 255), 4);
	mEngine->DrawFillCircle(Vector2(200.0f, 200.0f), 40.0f, Color(255, 255, 255), 3);
}

void TestGame::End()
{
}
