#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GUI.h"
#include "Node.h"
#include "Stack.hpp"

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
	sf::Font mFont;
	sf::Text mText;
	std::vector<Stack> stack;

public:
	Game();
	void Run();

private:
	void ProcessEvents();
	void Update();
	void Render();
	void AddNode(const std::string& data);
	void PopNode();
};