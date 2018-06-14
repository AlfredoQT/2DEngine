#pragma once

#include <cstddef>

class GameObject;

class GameObjectHandle
{
public:

	GameObjectHandle();

	GameObjectHandle(std::size_t pHash);

	bool IsValid();

	GameObject* Get();

private:

	std::size_t mHash;
};
