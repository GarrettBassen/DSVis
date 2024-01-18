#include <string>

#include "Game.h"

Game::Game()
	: m_window(sf::VideoMode(1500, 900), "DSV | Data Structure Visualization Tool | By: Garrett Bassen", sf::Style::Default, sf::ContextSettings(0, 0, 8))
	, m_view(sf::Vector2f(0.f,0.f), sf::Vector2f(1920.f, 1080.f))
	, m_isDragging(false)
	, m_mousePos(0, 0)
	, m_GUI(m_window)
	, m_zoom(1.f)
	, m_stack()
	, m_deque()
{
	sf::Image image;
	image.loadFromFile("assets/icon.png");
	m_window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

void Game::run() 
{
	while (m_window.isOpen())
	{
		process_events();
		update();
		render();
	}
}

void Game::process_events()
{
	while (m_window.pollEvent(m_event))
	{
		m_GUI.process_events(m_event);

		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::Resized:
			m_view.setSize(m_event.size.width, m_event.size.height);
			break;
		case sf::Event::MouseButtonPressed:
			m_isDragging = m_event.mouseButton.button == sf::Mouse::Right;
			m_mousePos = sf::Mouse::getPosition();
			break;
		case sf::Event::MouseButtonReleased:
			m_isDragging = false;
			break;
		case sf::Event::MouseWheelScrolled:
			m_view.zoom(1 + -m_event.mouseWheelScroll.delta / 20.f);
			break;
		}
	}
}

void Game::update() 
{
	m_window.setView(m_view);
	m_GUI.update(m_window);
	
	m_stack.update();
	m_deque.update();
	m_tree.update();

	if (m_clock.getElapsedTime().asSeconds() >= 1.f / 60.f) 
	{
		m_clock.restart();
		if (m_isDragging)
		{
			m_view.move(-(sf::Mouse::getPosition().x - m_mousePos.x), -(sf::Mouse::getPosition().y - m_mousePos.y));
			m_mousePos = sf::Mouse::getPosition();
		}
	}
}

void Game::render() 
{
	m_window.clear(sf::Color(185, 172, 154, 240));

	m_stack.render(m_window);
	m_deque.render(m_window);
	m_tree.render(m_window);
	m_GUI.render(m_window);

	ImGui::SFML::Render(m_window);
	m_window.display();
}