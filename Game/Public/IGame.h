#pragma once

class Engine;

// A simple interface for a game
class IGame
{
public:
	virtual void Init(Engine* pEngine) = 0;
	virtual void Run() = 0;
	virtual void End() = 0;

};
