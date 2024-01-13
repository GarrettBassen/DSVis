#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <memory>

#include "UITriggers.h"
#include "StackGUI.h"

class GUI {
private:
	ImGuiWindowFlags m_Flags;
	static sf::Clock m_Clock;
	StackGUI m_stackGUI;

public:
	GUI(sf::RenderWindow& window);
	~GUI();
	void ProcessEvents(const sf::Event& event);
	static void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

private:
	void InitStyle();
	void MainMenu();
	void AboutBar();

	void ListMenu();
};