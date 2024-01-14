#pragma once
#include "SFML/Graphics.hpp"
#include <string>

namespace UIHelper
{
	// For Stack and Deque
	struct Frame {
		std::string data;
		sf::Vector2f pos;
		sf::RectangleShape rect;
	};


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