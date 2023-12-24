#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/System/Clock.hpp>

class GUI {
private:
	ImGuiWindowFlags mNodeFlags;
	ImGuiWindowFlags mMainFlags;
	static sf::Clock mClock;
	char mDataStr[10] = "";

public:
	bool spawnNode;
	bool peekMenu;
	bool peek;
	bool pop;
	std::string spawnData;

public:
	GUI(sf::RenderWindow& window);
	~GUI();
	static void ProcessEvents(const sf::Event& event);
	static void Update(sf::RenderWindow& window);
	void Render(sf::RenderWindow& window);

private:
	void InitStyle();
	void MainMenu();
	void AboutBar();
};