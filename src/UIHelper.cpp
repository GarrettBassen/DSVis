#include "UIHelper.h"

// Stack Variables
bool UIHelper::showStack = false;
bool UIHelper::showStackPeek = false;

bool UIHelper::popStack = false;
bool UIHelper::peekStack = false;
bool UIHelper::pushStack = false;


// Deque Variables
bool UIHelper::showDeque = false;
bool UIHelper::showDequePeekFront = false;
bool UIHelper::showDequePeekBack = false;

bool UIHelper::popDequeFront = false;
bool UIHelper::popDequeBack = false;
bool UIHelper::peekDequeFront = false;
bool UIHelper::peekDequeBack = false;
bool UIHelper::pushDequeFront = false;
bool UIHelper::pushDequeBack = false;


// Tree Variables
bool UIHelper::showTree = false;;
bool UIHelper::insertTree = false;;
bool UIHelper::removeTree = false;;
bool UIHelper::rotateTreeLeft = false;;
bool UIHelper::rotateTreeRight = false;


// Used to transfer data across classes
std::string UIHelper::tmpData = "";