#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <string>

#include "UIHelper.h"

class TreeGUI {
private:
	ImGuiWindowFlags m_Flags;
	char m_data[10] = "";

public:
	TreeGUI();
	void menu();
};
