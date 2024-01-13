#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <string>

#include "UITriggers.h"

class DequeGUI {
private:
	ImGuiWindowFlags m_flags;
	char m_data[10] = "";

public:
	DequeGUI();
	void menu();
	void popup();
};