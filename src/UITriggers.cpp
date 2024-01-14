#include "UITriggers.h"

// Stack Variables
bool UITriggers::showStack = false;
bool UITriggers::showStackPeek = false;

bool UITriggers::popStack = false;
bool UITriggers::peekStack = false;
bool UITriggers::pushStack = false;


// Deque Variables
bool UITriggers::showDeque = false;
bool UITriggers::showDequePeekFront = false;
bool UITriggers::showDequePeekBack = false;

bool UITriggers::popDequeFront = false;
bool UITriggers::popDequeBack = false;
bool UITriggers::peekDequeFront = false;
bool UITriggers::peekDequeBack = false;
bool UITriggers::pushDequeFront = false;
bool UITriggers::pushDequeBack = false;


// Used to transfer data across classes
std::string UITriggers::tmpData = "";