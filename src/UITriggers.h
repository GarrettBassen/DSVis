#pragma once
#include <string>

namespace UITriggers 
{
	// Stack Variables
	extern bool showStack;
	extern bool showStackPeek;

	extern bool popStack;
	extern bool peekStack;
	extern bool pushStack;


	// Deque Variables
	extern bool showDeque;
	extern bool showDequePeekFront;
	extern bool showDequePeekBack;

	extern bool popDequeFront;
	extern bool popDequeBack;
	extern bool peekDequeFront;
	extern bool peekDequeBack;
	extern bool pushDequeFront;
	extern bool pushDequeBack;


	// Misc Variables
	extern std::string tmpData;
}