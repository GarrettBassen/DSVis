#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GUI.h"
#include "Node.h"

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
	std::vector<Node> mNodes;
	sf::Font mFont;
	sf::Text mText;

public:
	Game();
	void Run();

private:
	void ProcessEvents();
	void Update();
	void Render();
	void AddNode(const float data);
};