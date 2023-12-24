#pragma once
#include "SFML/Graphics.hpp"

class StackManager {
private:
	struct Frame {
		std::string data;
		sf::RectangleShape rect;
	};

	std::vector<Frame> mStack;
	sf::Vector2f mOffset;
	sf::Text mText;
	sf::Font mFont;

public:
	StackManager(const sf::Vector2f& location);
	void Push(const std::string& data);
	void Pop();
	const std::string Peek();
	void Render(sf::RenderWindow& window);
};