#pragma once
#include "SFML/Graphics.hpp"

class StackManager {
private:
	struct Frame {
		std::string data;
		sf::RectangleShape rect;
	};

	std::vector<Frame> mStack;
	sf::Text mText;
	sf::Font mFont;

public:
	StackManager();
	void Push(const std::string& data);
	void Pop();
	const std::string Peek();
	void UpdateOffset(const sf::Vector2i& offset);
	void Render(sf::RenderWindow& window);
};