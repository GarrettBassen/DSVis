#pragma once
#include <SFML/Graphics.hpp>

class Node {
public:
	sf::CircleShape circle;
	float data;

public:
	Node(const float data, const sf::Vector2f& location);
};