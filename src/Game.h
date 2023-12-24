#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GUI.h"
#include "Node.h"
#include "StackManager.h"

class Game {
private:
	sf::RenderWindow mWindow;
	sf::Event mEvent;
	sf::View mView;
	sf::Vector2i mMousePos;
	GUI mGUI;
	bool mIsDragging;
	sf::Clock mClock;
	float mZoom;
	StackManager mStack;

public:
	Game();
	void Run();

private:
	void ProcessEvents();
	void Update();
	void Render();
};