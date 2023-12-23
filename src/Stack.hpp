#pragma once
#include "SFML/Graphics.hpp"

class Stack {
public:
	sf::RectangleShape rect;
	std::string string;

public:
	Stack(const sf::RectangleShape& r, const sf::Vector2f& pos, const std::string& data)
		: rect(r)
		, string(data)
	{
		rect.setOrigin(r.getSize() / 2.f);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(1.f);
		rect.setPosition(pos);
	}
};