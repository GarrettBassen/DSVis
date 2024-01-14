#include <stdio.h>
#include <stdlib.h>

#include "GUI.h"

sf::Clock GUI::m_Clock;

GUI::GUI(sf::RenderWindow& window)
	: m_Flags(ImGuiWindowFlags_None)
{
	ImGui::SFML::Init(window);
	init_style();
}

GUI::~GUI() 
{
	ImGui::SFML::Shutdown();
}

void GUI::process_events(const sf::Event& event) 
{
	ImGui::SFML::ProcessEvent(event);
}

void GUI::update(sf::RenderWindow& window) 
{
	ImGui::SFML::Update(window, m_Clock.restart());
}

void GUI::render(sf::RenderWindow& window)
{
	// Standard menus
	if (UIHelper::showStack)		
	{ 
		m_stackGUI.menu();
	}
	else if (UIHelper::showDeque)
	{ 
		m_dequeGUI.menu(); 
	}
	else							
	{ 
		this->menu(); 
	}
	
	// Popup menus
	if (UIHelper::showStackPeek)											
	{ 
		m_stackGUI.popup(); 
	}
	else if (UIHelper::showDequePeekBack || UIHelper::showDequePeekFront)	
	{ 
		m_dequeGUI.popup(); 
	}
}

void GUI::menu() 
{
	ImGui::SetNextWindowSize(ImVec2(265.f, 122.f));
	ImGui::Begin("Control Panel", NULL, m_Flags);
	about_bar();

	if (ImGui::Button(("Stack"), ImVec2(120.f, 25.f))) { UIHelper::showStack = true; }
	ImGui::SameLine();
	if (ImGui::Button(("Deque"), ImVec2(120.f, 25.f))) { UIHelper::showDeque = true; }
	
	if (ImGui::Button(("TODO"), ImVec2(120.f, 25.f))) {}
	ImGui::SameLine();
	if (ImGui::Button(("TODO"), ImVec2(120.f, 25.f))) {}

	ImGui::End();
}

void GUI::about_bar()
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

void GUI::init_style() 
{
	m_Flags |= ImGuiWindowFlags_MenuBar;
	m_Flags |= ImGuiWindowFlags_AlwaysAutoResize;
	m_Flags |= ImGuiWindowFlags_NoCollapse;

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