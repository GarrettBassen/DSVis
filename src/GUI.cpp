#include "GUI.h"

ImGuiWindowFlags GUI::mNodeFlags = ImGuiWindowFlags_None;
ImGuiWindowFlags GUI::mMainFlags = ImGuiWindowFlags_None;
bool GUI::mIsInitialized = false;
sf::Clock GUI::mClock;

GUI::GUI(sf::RenderWindow& window)
	: spawnCircle(false)
	, spawnData(0.f)
{
	if (!mIsInitialized) {
		ImGui::SFML::Init(window);
		InitStyle();
		mIsInitialized = true;
	}
}

GUI::~GUI() {
	ImGui::SFML::Shutdown();
}

void GUI::ProcessEvents(const sf::Event& event) {
	ImGui::SFML::ProcessEvent(event);
}

void GUI::Update(sf::RenderWindow& window) {
	ImGui::SFML::Update(window, mClock.restart());
}

void GUI::Render(sf::RenderWindow& window) {
	ImGui::ShowDemoWindow();
	MainMenu();

	//ImGui::SFML::Render(window);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
// * * * * * * * * * * * * PRIVATE * * * * * * * * * * * *//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * *//

void GUI::MainMenu() {
	ImGui::Begin("Control Panel", NULL, mMainFlags);

	ImGui::BeginMenuBar();
	if (ImGui::BeginMenu("Menu"))
	{
		MenuBar();
		ImGui::EndMenu();
	}
	if (ImGui::BeginMenu("About"))
	{
		AboutBar();
		ImGui::EndMenu();
	}
	ImGui::EndMenuBar();

	if (ImGui::Button("Add Node", ImVec2(100.f, 19.f))) {
		spawnCircle = true;
		spawnData = atof(mDataStr);
	}
	ImGui::SameLine();
	ImGui::PushItemWidth(140.f);
	ImGui::InputTextWithHint(" ", "Node Data", mDataStr, sizeof(mDataStr), ImGuiInputTextFlags_CharsDecimal);
	ImGui::PopItemWidth();

	ImGui::Text("Number: %s", mDataStr);

	ImGui::End();
}

void GUI::AboutBar() {
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
}

void GUI::MenuBar() {
	ImGui::MenuItem("(demo menu)", NULL, false, false);
	if (ImGui::MenuItem("New")) {}
	if (ImGui::MenuItem("Open", "Ctrl+O")) {}
	if (ImGui::BeginMenu("Open Recent"))
	{
		ImGui::MenuItem("fish_hat.c");
		ImGui::MenuItem("fish_hat.inl");
		ImGui::MenuItem("fish_hat.h");
		if (ImGui::BeginMenu("More.."))
		{
			ImGui::MenuItem("Hello");
			ImGui::MenuItem("Sailor");
			ImGui::EndMenu();
		}
		ImGui::EndMenu();
	}
	if (ImGui::MenuItem("Save", "Ctrl+S")) {}
	if (ImGui::MenuItem("Save As..")) {}

	ImGui::Separator();
	if (ImGui::BeginMenu("Options"))
	{
		static bool enabled = true;
		ImGui::MenuItem("Enabled", "", &enabled);
		ImGui::BeginChild("child", ImVec2(0, 60), ImGuiChildFlags_Border);
		for (int i = 0; i < 10; i++)
			ImGui::Text("Scrolling Text %d", i);
		ImGui::EndChild();
		static float f = 0.5f;
		static int n = 0;
		ImGui::SliderFloat("Value", &f, 0.0f, 1.0f);
		ImGui::InputFloat("Input", &f, 0.1f);
		ImGui::Combo("Combo", &n, "Yes\0No\0Maybe\0\0");
		ImGui::EndMenu();
	}

	if (ImGui::BeginMenu("Colors"))
	{
		float sz = ImGui::GetTextLineHeight();
		for (int i = 0; i < ImGuiCol_COUNT; i++)
		{
			const char* name = ImGui::GetStyleColorName((ImGuiCol)i);
			ImVec2 p = ImGui::GetCursorScreenPos();
			ImGui::GetWindowDrawList()->AddRectFilled(p, ImVec2(p.x + sz, p.y + sz), ImGui::GetColorU32((ImGuiCol)i));
			ImGui::Dummy(ImVec2(sz, sz));
			ImGui::SameLine();
			ImGui::MenuItem(name);
		}
		ImGui::EndMenu();
	}
}

void GUI::InitStyle() {
	mMainFlags |= ImGuiWindowFlags_MenuBar;
	mMainFlags |= ImGuiWindowFlags_AlwaysAutoResize;
	mMainFlags |= ImGuiWindowFlags_NoCollapse;

	mNodeFlags |= ImGuiWindowFlags_NoBackground;
	mNodeFlags |= ImGuiWindowFlags_NoTitleBar;
	mNodeFlags |= ImGuiWindowFlags_NoResize;
	mNodeFlags |= ImGuiWindowFlags_NoMove;

	ImGuiStyle& mStyle = ImGui::GetStyle();
	mStyle.WindowRounding = 3;
	mStyle.FrameRounding = 1;
	mStyle.WindowTitleAlign = ImVec2(.5f, .5f);
	mStyle.SeparatorTextBorderSize = 4;
	mStyle.SeparatorTextPadding = ImVec2(15, 0);
	mStyle.FrameBorderSize = 1;

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