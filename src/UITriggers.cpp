#include "UITriggers.h"

// Stack Variables
bool UITriggers::showStack = false;
bool UITriggers::showStackPeek = false;

bool UITriggers::setStackPop = false;
bool UITriggers::getStackPeek = false;
bool UITriggers::pushStackElement = false;


// Deque Variables
bool UITriggers::showDeque = false;
bool UITriggers::showDequePeekFront = false;
bool UITriggers::showDequePeekBack = false;

bool UITriggers::setDequePopFront = false;
bool UITriggers::setDequePopBack = false;
bool UITriggers::getDequePeekFront = false;
bool UITriggers::getDequePeekBack = false;


// Used to transfer data across classes
std::string UITriggers::tmpData = "";