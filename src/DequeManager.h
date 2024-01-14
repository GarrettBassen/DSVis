#pragma once
#include "SFML/Graphics.hpp"

#include "UITriggers.h"

class DequeManager {
private:

public:
	DequeManager();
	void render(sf::RenderWindow& window);
	void update();

	void push_front();
	void push_back();
	void pop_front();
	void pop_back();
	void render();
	void peek_front();
	void peek_back();
};