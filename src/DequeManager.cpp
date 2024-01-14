#include "DequeManager.h"

DequeManager::DequeManager()
	: m_deque()
{
	m_font.loadFromFile("assets/Roboto-Regular.ttf");
	m_font.setSmooth(true);
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::Black);
	m_text.setCharacterSize(18.f);
}

void DequeManager::render(sf::RenderWindow& window)
{
	for (UIHelper::Frame f : m_deque)
	{
		m_text.setString(f.data);
		m_text.setPosition(f.rect.getPosition().x - 5.f - (f.data.size() * m_text.getCharacterSize()) / 4.f, f.rect.getPosition().y - m_text.getCharacterSize() / 2.f);

		window.draw(f.rect);
		window.draw(m_text);
	}
}

void DequeManager::update()
{
	if (UIHelper::pushDequeFront || UIHelper::pushDequeBack) { push(); }
	if (UIHelper::peekDequeFront || UIHelper::peekDequeBack) { peek(); }
	if (UIHelper::popDequeFront  || UIHelper::popDequeBack)  { pop();  }
}

void DequeManager::push()
{
	UIHelper::Frame f;
	f.rect.setSize(sf::Vector2f(100.f, 70.f));
	f.rect.setOrigin(f.rect.getSize() / 2.f);
	f.rect.setOutlineColor(sf::Color::Black);
	f.rect.setOutlineThickness(1.f);
	f.data = UIHelper::tmpData;

	if (m_deque.empty())
	{
		f.pos = sf::Vector2f(0.f, 0.f);
		f.rect.setPosition(f.pos);
		m_deque.push_front(f);
	}
	else if (UIHelper::pushDequeFront)
	{
		f.pos = sf::Vector2f(m_deque.front().pos.x + 101.f, 0.f);
		f.rect.setPosition(f.pos);
		m_deque.push_front(f);
	}
	else
	{
		f.pos = sf::Vector2f(m_deque.back().pos.x - 101.f, 0.f);
		f.rect.setPosition(f.pos);
		m_deque.push_back(f);
	}

	UIHelper::pushDequeFront = false;
	UIHelper::pushDequeBack = false;
}

void DequeManager::peek()
{
	if (UIHelper::peekDequeFront)
	{
		UIHelper::peekDequeFront = false;
		UIHelper::tmpData = m_deque.empty() ? "NULL" : m_deque.front().data;
		UIHelper::showDequePeekFront = true;
	}
	else
	{
		UIHelper::peekDequeBack = false;
		UIHelper::tmpData = m_deque.empty() ? "NULL" : m_deque.back().data;
		UIHelper::showDequePeekBack = true;
	}
}

void DequeManager::pop()
{
	if (UIHelper::popDequeFront)
	{
		UIHelper::popDequeFront = false;
		if (!m_deque.empty())
		{
			m_deque.pop_front();
		}
	}
	else
	{
		UIHelper::popDequeBack = false;
		if (!m_deque.empty())
		{
			m_deque.pop_back();
		}
	}
}