#pragma once
#include <SFML/Graphics.hpp>
#include "GUI.h"

class Game {
private:
	sf::RenderWindow mWindow;
	sf::Event mEvent;
	GUI mGUI;

public:
	Game();
	void Run();

private:
	void ProcessEvents();
	void Update();
	void Render();
};