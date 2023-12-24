#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

class GUI {
private:
	ImGuiWindowFlags mNodeFlags;
	ImGuiWindowFlags mMainFlags;
	static sf::Clock mClock;
	char mDataStr[10] = "";
	bool mStackMenu;

public:
	bool spawnElement;
	bool peekMenu;
	bool peek;
	bool pop;
	std::string spawnData;

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

	void StackMenu();
	void PeekPopup();
};