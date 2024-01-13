#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GUI.h"
#include "Node.h"
#include "StackManager.h"

class Game {
private:
	sf::RenderWindow m_window;
	sf::Vector2i m_mousePos;
	sf::Clock m_clock;
	sf::Event m_event;
	sf::View m_view;

	bool m_isDragging;
	float m_zoom;

	StackManager m_stack;
	GUI m_GUI;

public:
	Game();
	void Run();

private:
	void ProcessEvents();
	void Update();
	void Render();
};