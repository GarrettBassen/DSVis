#include "TreeGUI.h"

TreeGUI::TreeGUI()
	: m_Flags(ImGuiWindowFlags_None)
{
	m_Flags |= ImGuiWindowFlags_AlwaysAutoResize;
	m_Flags |= ImGuiWindowFlags_NoCollapse;
}

void TreeGUI::menu()
{
	ImGui::SetNextWindowSize(ImVec2(265.f, 128.f));
	ImGui::Begin("Tree Panel", &UIHelper::showTree, m_Flags);

	ImGui::PushItemWidth(250.f);
	ImGui::InputTextWithHint(" ", "Node Data", m_data, sizeof(m_data));
	ImGui::PopItemWidth();

	if (ImGui::Button("Remove", ImVec2(120.f, 25.f)) && m_data[0] != 0 && m_data[0] != 32)
	{
		UIHelper::tmpData = m_data;
		UIHelper::insertTree = true;
	}
	ImGui::SameLine();
	if (ImGui::Button("Insert", ImVec2(120.f, 25.f)) && m_data[0] != 0 && m_data[0] != 32)
	{
		UIHelper::tmpData = m_data;
		UIHelper::removeTree = true;
	}

	if (ImGui::Button("Rotate Left", ImVec2(120.f, 25.f)) && m_data[0] != 0 && m_data[0] != 32)
	{
		UIHelper::tmpData = m_data;
		UIHelper::rotateTreeLeft = true;
	}
	ImGui::SameLine();
	if (ImGui::Button("Rotate Right", ImVec2(120.f, 25.f)) && m_data[0] != 0 && m_data[0] != 32)
	{
		UIHelper::tmpData = m_data;
		UIHelper::rotateTreeRight = true;
	}

	ImGui::End();
}