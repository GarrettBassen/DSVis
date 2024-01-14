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
		m_text.setPosition(f.rect.getPosition().x - 4.f - (f.data.size() * m_text.getCharacterSize()) / 4.f, f.rect.getPosition().y - m_text.getCharacterSize() / 2.f);

		window.draw(f.rect);
		window.draw(m_text);
	}
}

void DequeManager::update()
{
	if (UIHelper::pushDequeFront) { push_front(); }
	if (UIHelper::pushDequeBack)  { push_back(); }
	if (UIHelper::popDequeFront)  { pop_front();  }
	if (UIHelper::popDequeBack)	  { pop_back();   }
	if (UIHelper::peekDequeFront) { peek_front(); }
	if (UIHelper::peekDequeBack)  { peek_back();  }
}

void DequeManager::push_front()
{
	UIHelper::pushDequeFront = false;
	UIHelper::Frame f;
	f.rect.setSize(sf::Vector2f(100.f, 70.f));
	f.rect.setOrigin(f.rect.getSize() / 2.f);
	f.rect.setOutlineColor(sf::Color::Black);
	f.rect.setOutlineThickness(1.f);
	f.rect.setPosition(sf::Vector2f(m_deque.size() * 100.f + m_deque.size(), 0.f));
	f.data = UIHelper::tmpData;

	m_deque.push_front(f);
	UIHelper::tmpData = "NULL";
}

void DequeManager::push_back()
{
	UIHelper::pushDequeBack = false;

	// TODO

	UIHelper::tmpData = "NULL";
}

void DequeManager::pop_front()
{
	UIHelper::popDequeFront = false;
	if (!m_deque.empty())
	{
		m_deque.pop_front();
	}
}

void DequeManager::pop_back()
{
	UIHelper::popDequeBack = false;
	if (!m_deque.empty())
	{
		m_deque.pop_back();
	}
}

void DequeManager::peek_front()
{
	UIHelper::peekDequeFront = false;
	UIHelper::tmpData = m_deque.empty() ? "NULL" : m_deque.front().data;
	UIHelper::showDequePeekFront = true;
}

void DequeManager::peek_back()
{
	UIHelper::peekDequeBack = false;
	UIHelper::tmpData = m_deque.empty() ? "NULL" : m_deque.back().data;
	UIHelper::showDequePeekBack = true;
}