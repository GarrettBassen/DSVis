#include <string>

#include "Game.h"
#include "UITriggers.h"

Game::Game()
	: mWindow(sf::VideoMode(1500, 900), "DSV | Data Structure Visualization Tool | By: Garrett Bassen", sf::Style::Default, sf::ContextSettings(0, 0, 8))
	, mView(sf::Vector2f(0.f,0.f), sf::Vector2f(1920.f, 1080.f))
	, mStack()
	, mIsDragging(false)
	, mMousePos(0, 0)
	, mGUI(mWindow)
	, mZoom(1.f)
{
	sf::Image image;
	image.loadFromFile("assets/icon.png");
	mWindow.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

void Game::Run() 
{
	while (mWindow.isOpen()) 
	{
		ProcessEvents();
		Update();
		Render();
	}
}

void Game::ProcessEvents()
{
	while (mWindow.pollEvent(mEvent))
	{
		mGUI.ProcessEvents(mEvent);

		switch (mEvent.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		case sf::Event::Resized:
			mView.setSize(mEvent.size.width, mEvent.size.height);
			break;
		case sf::Event::MouseButtonPressed:
			mIsDragging = mEvent.mouseButton.button == sf::Mouse::Right;
			mMousePos = sf::Mouse::getPosition();
			break;
		case sf::Event::MouseButtonReleased:
			mIsDragging = false;
			break;
		case sf::Event::MouseWheelScrolled:
			mView.zoom(1 + -mEvent.mouseWheelScroll.delta / 20.f);
			break;
		}
	}
}

void Game::Update() 
{
	mWindow.setView(mView);
	mGUI.Update(mWindow);
	
	if (UITriggers::pushStackElement)
	{
		UITriggers::pushStackElement = false;
		mStack.Push(UITriggers::tmpData);
		UITriggers::tmpData = "NULL";
	}
	if (UITriggers::setStackPop) 
	{
		UITriggers::setStackPop = false;
		mStack.Pop();
	}
	if (UITriggers::getStackPeek)
	{
		UITriggers::getStackPeek = false;
		UITriggers::tmpData = mStack.Peek();
		UITriggers::showStackPeek = true;
	}

	if (mClock.getElapsedTime().asSeconds() >= 1.f / 60.f) 
	{
		mClock.restart();
		if (mIsDragging)
		{
			mView.move(-(sf::Mouse::getPosition().x - mMousePos.x), -(sf::Mouse::getPosition().y - mMousePos.y));
			mMousePos = sf::Mouse::getPosition();
		}
	}
}

void Game::Render() 
{
	mWindow.clear(sf::Color(185, 172, 154, 240));

	mStack.Render(mWindow);
	mGUI.Render(mWindow);

	ImGui::SFML::Render(mWindow);
	mWindow.display();
}