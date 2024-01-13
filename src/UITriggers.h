#pragma once
#include <string>

namespace UITriggers 
{
	// Stack Variables
	extern bool showStack;
	extern bool showStackPeek;

	extern bool setStackPop;
	extern bool getStackPeek;
	extern bool pushStackElement;


	// Deque Variables
	extern bool showDeque;
	extern bool showDequePeekFront;
	extern bool showDequePeekBack;

	extern bool setDequePopFront;
	extern bool setDequePopBack;
	extern bool getDequePeekFront;
	extern bool getDequePeekBack;


	// Misc Variables
	extern std::string tmpData;
}