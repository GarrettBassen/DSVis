#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(1500, 900), "DSV | Data Structure Visualization Tool | By: Garrett Bassen", sf::Style::Default, sf::ContextSettings(0, 0, 8))
	, mGUI(mWindow)
{
	sf::Image image;
	image.loadFromFile("assets/icon.png");
	mWindow.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
}

void Game::Run() {
	while (mWindow.isOpen()) {
		ProcessEvents();
		Update();
		Render();
	}
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
// * * * * * * * * * * * * PRIVATE * * * * * * * * * * * *//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * *//

void Game::ProcessEvents() {
	while (mWindow.pollEvent(mEvent)) {
		mGUI.ProcessEvents(mEvent);
		
		if (mEvent.type == sf::Event::Closed)
			mWindow.close();
	}

}

void Game::Update() {
	mGUI.Update(mWindow);
}

void Game::Render() {
	mWindow.clear(sf::Color(185, 172, 154, 240));
	mGUI.Render(mWindow);

	mWindow.display();
}