#include "GUI.h"
#include <stdio.h>
#include <stdlib.h>

sf::Clock GUI::mClock;

GUI::GUI(sf::RenderWindow& window)
	: mMainFlags(ImGuiWindowFlags_None)
	, mNodeFlags(ImGuiWindowFlags_None)
	, spawnElement(false)
	, peekMenu(false)
	, peek(false)
	, pop(false)
	, spawnData("NULL")
	, mStackMenu(false)
{
	ImGui::SFML::Init(window);
	InitStyle();
}

GUI::~GUI() 
{
	ImGui::SFML::Shutdown();
}

void GUI::ProcessEvents(const sf::Event& event) 
{
	ImGui::SFML::ProcessEvent(event);
}

void GUI::Update(sf::RenderWindow& window) 
{
	ImGui::SFML::Update(window, mClock.restart());
}

void GUI::Render(sf::RenderWindow& window) 
{
	//ImGui::ShowDemoWindow();
	if (mStackMenu) StackMenu();
	else MainMenu();
	
	if (peekMenu) PeekPopup();
}

void GUI::MainMenu() 
{
	ImGui::SetNextWindowSize(ImVec2(265.f, 122.f));
	ImGui::Begin("Control Panel", NULL, mMainFlags);
	AboutBar();

	if (ImGui::Button(("Stack"), ImVec2(120.f, 25.f))) { mStackMenu = true; }
	ImGui::SameLine();
	if (ImGui::Button(("TODO"), ImVec2(120.f, 25.f))) {}
	
	if (ImGui::Button(("TODO"), ImVec2(120.f, 25.f))) {}
	ImGui::SameLine();
	if (ImGui::Button(("TODO"), ImVec2(120.f, 25.f))) {}

	ImGui::End();
}

void GUI::StackMenu() 
{
	ImGui::SetNextWindowSize(ImVec2(265.f, 122.f));
	ImGui::Begin("Stack Panel", &mStackMenu, mMainFlags);
	AboutBar();

	if (ImGui::Button("Push", ImVec2(120.f, 25.f)) && mDataStr[0] != 0 && mDataStr[0] != 32) 
	{
		spawnElement = true;
		spawnData = mDataStr;
	}
	ImGui::SameLine();
	ImGui::PushItemWidth(120.f);
	ImGui::InputTextWithHint(" ", "Node Data", mDataStr, sizeof(mDataStr));
	ImGui::PopItemWidth();

	if (ImGui::Button("Pop", ImVec2(120.f, 25.f))) { pop = true; }
	ImGui::SameLine();
	if (ImGui::Button("Peek", ImVec2(120.f, 25.f))) { peek = true; }

	ImGui::End();
}

void GUI::PeekPopup() 
{
	ImVec2 center = ImGui::GetMainViewport()->GetCenter();
	ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

	ImGui::OpenPopup("Peek Info");
	if (ImGui::BeginPopupModal("Peek Info", NULL, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("The top of the stack is %s", &spawnData);
		ImGui::Separator();

		if (ImGui::Button("OK", ImVec2(190, 0))) { peekMenu = false; }

		ImGui::EndPopup();
	}
}

void GUI::AboutBar() 
{
	ImGui::BeginMenuBar();
	if (ImGui::BeginMenu("About")) 
	{
		ImGui::MenuItem("Made By: Garrett Bassen 12/2023", NULL, false, false);
		ImGui::MenuItem("Program uses SFML and Dear imgui", NULL, false, false);
		ImGui::Separator();

		ImGui::Button("Copy Github Account Link");
		if (ImGui::BeginItemTooltip())
		{
			ImGui::Text("https://github.com/GarrettBassen");
			ImGui::LogToClipboard();
			ImGui::LogText("https://github.com/GarrettBassen");
			ImGui::LogFinish();
			ImGui::EndTooltip();
		}
		ImGui::EndMenu();
	}
	ImGui::EndMenuBar();
}

void GUI::InitStyle() 
{
	mMainFlags |= ImGuiWindowFlags_MenuBar;
	mMainFlags |= ImGuiWindowFlags_AlwaysAutoResize;
	mMainFlags |= ImGuiWindowFlags_NoCollapse;

	mNodeFlags |= ImGuiWindowFlags_NoBackground;
	mNodeFlags |= ImGuiWindowFlags_NoTitleBar;
	mNodeFlags |= ImGuiWindowFlags_NoResize;
	mNodeFlags |= ImGuiWindowFlags_NoMove;

	ImGuiStyle& mStyle = ImGui::GetStyle();
	mStyle.ScaleAllSizes(2.f);
	mStyle.WindowRounding = 3;
	mStyle.FrameRounding = 1;
	mStyle.WindowTitleAlign = ImVec2(.5f, .5f);
	mStyle.SeparatorTextBorderSize = 4;
	mStyle.SeparatorTextPadding = ImVec2(15, 0);
	mStyle.FrameBorderSize = 1;
	mStyle.WindowPadding = ImVec2(8.f, 8.f);
	mStyle.ItemSpacing = ImVec2(8.f, 6.f);

	ImVec4* mColors = ImGui::GetStyle().Colors;
	mColors = ImGui::GetStyle().Colors;
	mColors[ImGuiCol_Text] = ImVec4(0.10f, 0.03f, 0.23f, 1.00f);
	mColors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	mColors[ImGuiCol_WindowBg] = ImVec4(0.92f, 0.89f, 0.85f, 1.00f);
	mColors[ImGuiCol_ChildBg] = ImVec4(0.88f, 0.85f, 0.85f, 1.00f);
	mColors[ImGuiCol_PopupBg] = ImVec4(0.88f, 0.85f, 0.85f, 1.00f);
	mColors[ImGuiCol_Border] = ImVec4(0.39f, 0.44f, 0.48f, 0.50f);
	mColors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	mColors[ImGuiCol_FrameBg] = ImVec4(0.66f, 0.74f, 0.75f, 1.00f);
	mColors[ImGuiCol_FrameBgHovered] = ImVec4(0.81f, 0.86f, 0.87f, 1.00f);
	mColors[ImGuiCol_FrameBgActive] = ImVec4(0.82f, 0.86f, 0.87f, 1.00f);
	mColors[ImGuiCol_TitleBg] = ImVec4(0.65f, 0.65f, 0.65f, 1.00f);
	mColors[ImGuiCol_TitleBgActive] = ImVec4(0.49f, 0.61f, 0.34f, 1.00f);
	mColors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.88f, 0.89f, 0.86f, 1.00f);
	mColors[ImGuiCol_MenuBarBg] = ImVec4(0.79f, 0.82f, 0.71f, 1.00f);
	mColors[ImGuiCol_ScrollbarBg] = ImVec4(0.43f, 0.43f, 0.43f, 0.53f);
	mColors[ImGuiCol_ScrollbarGrab] = ImVec4(0.37f, 0.38f, 0.38f, 1.00f);
	mColors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	mColors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	mColors[ImGuiCol_CheckMark] = ImVec4(0.88f, 0.97f, 0.99f, 1.00f);
	mColors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.95f, 0.97f, 1.00f);
	mColors[ImGuiCol_SliderGrabActive] = ImVec4(0.51f, 0.78f, 0.83f, 1.00f);
	mColors[ImGuiCol_Button] = ImVec4(0.43f, 0.54f, 0.69f, 0.40f);
	mColors[ImGuiCol_ButtonHovered] = ImVec4(0.67f, 0.80f, 0.53f, 1.00f);
	mColors[ImGuiCol_ButtonActive] = ImVec4(0.71f, 0.85f, 0.58f, 1.00f);
	mColors[ImGuiCol_Header] = ImVec4(0.32f, 0.42f, 0.55f, 0.31f);
	mColors[ImGuiCol_HeaderHovered] = ImVec4(0.75f, 0.85f, 0.60f, 0.80f);
	mColors[ImGuiCol_HeaderActive] = ImVec4(0.58f, 0.80f, 0.65f, 1.00f);
	mColors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	mColors[ImGuiCol_SeparatorHovered] = ImVec4(0.65f, 0.72f, 0.81f, 0.78f);
	mColors[ImGuiCol_SeparatorActive] = ImVec4(0.48f, 0.66f, 0.27f, 1.00f);
	mColors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
	mColors[ImGuiCol_ResizeGripHovered] = ImVec4(0.80f, 0.84f, 0.70f, 0.67f);
	mColors[ImGuiCol_ResizeGripActive] = ImVec4(0.80f, 0.85f, 0.60f, 0.95f);
	mColors[ImGuiCol_Tab] = ImVec4(0.39f, 0.46f, 0.55f, 0.86f);
	mColors[ImGuiCol_TabHovered] = ImVec4(0.53f, 0.69f, 0.40f, 0.80f);
	mColors[ImGuiCol_TabActive] = ImVec4(0.43f, 0.60f, 0.30f, 0.80f);
	mColors[ImGuiCol_TabUnfocused] = ImVec4(0.28f, 0.39f, 0.52f, 0.97f);
	mColors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
	mColors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	mColors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	mColors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
	mColors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	mColors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
	mColors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
	mColors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
	mColors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	mColors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	mColors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
	mColors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	mColors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
	mColors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	mColors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
	mColors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}