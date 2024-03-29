#include "StackGUI.h"

StackGUI::StackGUI()
	: m_Flags(ImGuiWindowFlags_None)
{
	m_Flags |= ImGuiWindowFlags_AlwaysAutoResize;
	m_Flags |= ImGuiWindowFlags_NoCollapse;
}

void StackGUI::menu()
{
	ImGui::SetNextWindowSize(ImVec2(265.f, 98.f));
	ImGui::Begin("Stack Panel", &UIHelper::showStack, m_Flags);

	if (ImGui::Button("Push", ImVec2(120.f, 25.f)) && m_data[0] != 0 && m_data[0] != 32)
	{
		UIHelper::tmpData = m_data;
		UIHelper::pushStack = true;
	}
	ImGui::SameLine();
	ImGui::PushItemWidth(120.f);
	ImGui::InputTextWithHint(" ", "Node Data", m_data, sizeof(m_data));
	ImGui::PopItemWidth();

	if (ImGui::Button("Pop", ImVec2(120.f, 25.f))) { UIHelper::popStack = true; }
	ImGui::SameLine();
	if (ImGui::Button("Peek", ImVec2(120.f, 25.f))) { UIHelper::peekStack = true; }

	ImGui::End();
}

void StackGUI::popup()
{
	ImVec2 center = ImGui::GetMainViewport()->GetCenter();
	ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

	ImGui::OpenPopup("Peek Info");
	if (ImGui::BeginPopupModal("Peek Info", NULL, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("The top of the stack is: %s", UIHelper::tmpData.c_str());
		ImGui::Separator();

		if (ImGui::Button("OK", ImVec2(190, 0))) 
		{ 
			UIHelper::showStackPeek = false;
			UIHelper::tmpData = "NULL";
		}

		ImGui::EndPopup();
	}
}