#include "DequeGUI.h"

DequeGUI::DequeGUI()
	: m_flags(ImGuiWindowFlags_None)
{
	m_flags |= ImGuiWindowFlags_AlwaysAutoResize;
	m_flags |= ImGuiWindowFlags_NoCollapse;
}

void DequeGUI::menu()
{
	ImGui::SetNextWindowSize(ImVec2(265.f, 159.f));
	ImGui::Begin("Deque Panel", &UITriggers::showDeque, m_flags);

	ImGui::PushItemWidth(250.f);
	ImGui::InputTextWithHint(" ", "Node Data", m_data, sizeof(m_data));
	ImGui::PopItemWidth();

	if (ImGui::Button("Push Front", ImVec2(120.f, 25.f)) && m_data[0] != 0 && m_data[0] != 32)
	{
		UITriggers::pushDequeFront = true;
	}
	ImGui::SameLine();
	if (ImGui::Button("Push Back", ImVec2(120.f, 25.f)) && m_data[0] != 0 && m_data[0] != 32)
	{
		UITriggers::pushDequeBack = true;
	}

	if (ImGui::Button("Pop Front", ImVec2(120.f, 25.f)))
	{
		UITriggers::popDequeFront = true;
	}
	ImGui::SameLine();
	if (ImGui::Button("Pop Back", ImVec2(120.f, 25.f)))
	{
		UITriggers::popDequeBack = true;
	}

	if (ImGui::Button("Peek Front", ImVec2(120.f, 25.f)))
	{
		UITriggers::peekDequeFront = true;
	}
	ImGui::SameLine();
	if (ImGui::Button("Peek Back", ImVec2(120.f, 25.f)))
	{
		UITriggers::peekDequeBack = true;
	}

	ImGui::End();
}

void DequeGUI::popup()
{
	ImVec2 center = ImGui::GetMainViewport()->GetCenter();
	ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

	ImGui::OpenPopup("Deque Peek");
	if (ImGui::BeginPopupModal("Deque Peek", NULL, ImGuiWindowFlags_AlwaysAutoResize))
	{
		if (UITriggers::showDequePeekFront)
		{
			ImGui::Text("The front of the deque is: %s", UITriggers::tmpData.c_str());
		}
		else if (UITriggers::showDequePeekBack)
		{
			ImGui::Text("The back of the deque is: %s", UITriggers::tmpData.c_str());
		}
		ImGui::Separator();

		if (ImGui::Button("OK", ImVec2(190, 0)))
		{
			UITriggers::showDequePeekBack = false;
			UITriggers::showDequePeekFront = false;
			UITriggers::tmpData = "NULL";
		}

		ImGui::EndPopup();
	}
}