#include "TreeManager.h"

TreeManager::TreeManager()
	: m_tree()
{
	m_font.loadFromFile("assets/Roboto-Regular.ttf");
	m_font.setSmooth(true);
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(18.f);
}

void TreeManager::render(sf::RenderWindow& window)
{
	for (UIHelper::Node f : m_tree)
	{
		m_text.setString(f.data);

		m_text.setPosition(f.pos.x, f.pos.y); // TODO Change text location
		f.circle.setPosition(f.pos);

		window.draw(f.circle);
		window.draw(m_text);
	}
}

void TreeManager::update()
{
	if (UIHelper::insertTree)									{ insert(); }
	if (UIHelper::removeTree)									{ remove(); }
	if (UIHelper::rotateTreeLeft || UIHelper::rotateTreeRight)	{ rotate(); }
	// UPDATE POSITION AND DETECT NODE MOVEMENT
}

void TreeManager::insert()
{
	UIHelper::insertTree = false;

	UIHelper::Node node;

	sf::Vector2f position(0.f, 0.f); // TODO GET NODE POSITION
	// TODO SET POSITION DEPENDENT ON PREVIOUS NODE IF APPLICABLE

	node.pos = position;

	node.data = UIHelper::tmpData;
	node.circle.setRadius(40.f);
	//node.circle.setOrigin(node.pos.x + node.circle.getRadius(), node.pos.y + node.circle.getRadius());
	node.circle.setFillColor(sf::Color::White);
	node.circle.setOutlineColor(sf::Color::Black);
	node.circle.setOutlineThickness(1.f);

	m_tree.push_back(node);
}

void TreeManager::remove()
{
	UIHelper::removeTree = false;
	
	for (UIHelper::Node n : m_tree)
	{
		if (n.data == UIHelper::tmpData);
	}
}

void TreeManager::rotate()
{

}