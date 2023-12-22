#include "Node.h"

Node::Node(const float data, const sf::Vector2f& location)
	: data(data)
{
	circle.setRadius(60.f);
	circle.setOrigin(30.f, 30.f);
	circle.setFillColor(sf::Color(215, 245, 238, 255));
	circle.setPosition(location);
}