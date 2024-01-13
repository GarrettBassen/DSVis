#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <string>

#include "UITriggers.h"

class StackGUI {
private:
	ImGuiWindowFlags m_Flags;
	char m_data[10] = "";

public:
	StackGUI();
	void StackMenu();
	void PeekPopup();
};