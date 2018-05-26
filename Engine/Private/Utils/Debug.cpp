#include "..\..\Public\Utils\Debug.h"
#include "windows.h"

void Debug::OutputLine(const char * output)
{
	OutputDebugString(output);
	OutputDebugString("\n");
}

void Debug::OutputLine(std::string text)
{
	const char* finalChar = text.c_str();
	OutputLine(finalChar);
}

void Debug::OutputLine(uint64_t input)
{
	std::string str = std::to_string(input);
	OutputLine(str.c_str());
}

void Debug::OutputLine(float input)
{
	std::string str = std::to_string(input);
	OutputLine(str.c_str());
}
