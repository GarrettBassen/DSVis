#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <memory>

#include "UITriggers.h"
#include "StackGUI.h"
#include "DequeGUI.h"

class GUI {
private:
	ImGuiWindowFlags m_Flags;
	static sf::Clock m_Clock;
	StackGUI m_stackGUI;
	DequeGUI m_dequeGUI;

public:
	GUI(sf::RenderWindow& window);
	~GUI();
	void process_events(const sf::Event& event);
	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);

private:
	void init_style();
	void menu();
	void about_bar();
};