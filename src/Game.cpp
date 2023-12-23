#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(1500, 900), "DSV | Data Structure Visualization Tool | By: Garrett Bassen", sf::Style::Default, sf::ContextSettings(0, 0, 8))
	, mView(sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f))
	, mIsDragging(false)
	, mMousePos(0, 0)
	, mGUI(mWindow)
	, mZoom(1.f)
{
	mView.setSize(mWindow.getSize().x, mWindow.getSize().y);
	sf::Image image;
	image.loadFromFile("assets/icon.png");
	mWindow.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
	mFont.loadFromFile("assets/Roboto-Regular.ttf");
	mFont.setSmooth(true);
	mText.setFillColor(sf::Color::Black);
	mText.setFont(mFont);
	mText.setCharacterSize(18.f);
}

void Game::Run() {
	while (mWindow.isOpen()) {
		ProcessEvents();
		Update();
		Render();
	}
}

void Game::AddNode(const std::string& data) {
	mGUI.spawnCircle = false;
	stack.push_back(Stack(sf::RectangleShape(sf::Vector2f(100.f, 70.f)), sf::Vector2f(0.f, (stack.size() * -70.f - stack.size())), data));
}

void Game::PopNode() {
	if (!stack.empty()) {
		stack.pop_back();
		if (!stack.empty()) mGUI.spawnData = stack.at(stack.size() - 1).string;
		else mGUI.spawnData = "NULL";
	}
	mGUI.pop = false;
}

void Game::ProcessEvents() {
	while (mWindow.pollEvent(mEvent)) {
		mGUI.ProcessEvents(mEvent);
		
		switch (mEvent.type) {
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

void Game::Update() {
	mWindow.setView(mView);
	mGUI.Update(mWindow);
	
	if (mGUI.spawnCircle)
		AddNode(mGUI.spawnData);
	if (mGUI.pop)
		PopNode();

	if (mClock.getElapsedTime().asSeconds() >= 1.f / 60.f) {
		mClock.restart();
		if (mIsDragging) {
			mView.move(-(sf::Mouse::getPosition().x - mMousePos.x), -(sf::Mouse::getPosition().y - mMousePos.y));
			mMousePos = sf::Mouse::getPosition();
		}
	}
}

void Game::Render() {
	mWindow.clear(sf::Color(185, 172, 154, 240));

	for (Stack s : stack) {
		mText.setString(s.string);
		mText.setPosition(s.rect.getPosition().x - (s.string.size() * mText.getCharacterSize()) / 4.f, s.rect.getPosition().y - mText.getCharacterSize() / 2.f);
		mWindow.draw(s.rect);
		mWindow.draw(mText);
	}

	mGUI.Render(mWindow);
	ImGui::SFML::Render(mWindow);
	mWindow.display();
}