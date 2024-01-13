#include "StackManager.h"

StackManager::StackManager()
	: m_stack()
{
	m_font.loadFromFile("assets/Roboto-Regular.ttf");
	m_font.setSmooth(true);
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(18.f);
}

void StackManager::Push(const std::string& data) 
{
	Frame f;
	f.rect.setSize(sf::Vector2f(100.f, 70.f));
	f.rect.setOrigin(f.rect.getSize() / 2.f);
	f.rect.setOutlineColor(sf::Color::Black);
	f.rect.setOutlineThickness(1.f);
	f.rect.setPosition(sf::Vector2f(0.f, m_stack.size() * -70.f - m_stack.size()));
	f.data = data;

	m_stack.push_back(f);
}

void StackManager::Pop() 
{
	if (!m_stack.empty())
		m_stack.pop_back();
}

const std::string StackManager::Peek()
{
	return m_stack.empty() ? "NULL" : m_stack.back().data;
}

void StackManager::Render(sf::RenderWindow& window) 
{
	for (Frame f : m_stack)
	{
		m_text.setString(f.data);
		m_text.setPosition(f.rect.getPosition().x - 4.f - (f.data.size() * m_text.getCharacterSize()) / 4.f, f.rect.getPosition().y - m_text.getCharacterSize() / 2.f);

		window.draw(f.rect);
		window.draw(m_text);
	}
}