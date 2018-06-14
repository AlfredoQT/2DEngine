#pragma once

#include <string>

// I chose overloading because I could not print std::string
namespace Debug
{
	void OutputLine(const char* output);

	void OutputLine(std::string text);

	void OutputLine(uint64_t input);

	void OutputLine(float input);

	void OutputLine(int input);

	void OutputLine(bool input);
}
