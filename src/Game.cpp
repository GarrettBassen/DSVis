#include "Game.h"
#include <iomanip>
#include <sstream>

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

void Game::AddNode(const float data) {
	mGUI.spawnCircle = false;
	mNodes.push_back(Node(data, sf::Vector2f(rand() / 1000.f, rand()/1000.f)));
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * *//
// * * * * * * * * * * * * PRIVATE * * * * * * * * * * * *//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * *//

void Game::ProcessEvents() {
	while (mWindow.pollEvent(mEvent)) {
		mGUI.ProcessEvents(mEvent);
		
		if (mEvent.type == sf::Event::Closed)
			mWindow.close();

		if (mEvent.type == sf::Event::Resized)
			mView.setSize(mEvent.size.width, mEvent.size.height);

		if (mEvent.type == sf::Event::MouseButtonPressed) {
			if (mEvent.mouseButton.button == sf::Mouse::Right) {
				mMousePos = sf::Mouse::getPosition();
				mIsDragging = true;
			}
		}

		if (mEvent.type == sf::Event::MouseButtonReleased) {
			mIsDragging = false;
		}

		if (mEvent.type == sf::Event::MouseWheelScrolled) {
			float offset = -mEvent.mouseWheelScroll.delta / 20.f;
			mZoom += offset;
			mView.zoom(1 + offset);
		}
	}

}

void Game::Update() {
	mWindow.setView(mView);
	
	if (mGUI.spawnCircle) {
		AddNode(mGUI.spawnData);
	}

	mGUI.Update(mWindow);

	if (mClock.getElapsedTime().asSeconds() >= 1.f / 60.f) {
		mClock.restart();
		if (mIsDragging) {
			float dt = mClock.restart().asSeconds();
			mView.move(-(sf::Mouse::getPosition().x - mMousePos.x) * mZoom, -(sf::Mouse::getPosition().y - mMousePos.y) * mZoom);
			mMousePos = sf::Mouse::getPosition();
		}
	}
}

void Game::Render() {
	ImGuiWindowFlags NodeFlags;
	NodeFlags = ImGuiWindowFlags_None;
	NodeFlags |= ImGuiWindowFlags_NoBackground;
	NodeFlags |= ImGuiWindowFlags_NoTitleBar;
	NodeFlags |= ImGuiWindowFlags_NoResize;
	NodeFlags |= ImGuiWindowFlags_NoMove;

	mWindow.clear(sf::Color(185, 172, 154, 240));

	ImGui::Begin("DEBUG");
	ImGui::Text("Zoom: %f", mZoom);
	ImGui::End();

	for (Node n : mNodes) {
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << n.data;
		mText.setString(stream.str());
		mText.setPosition(sf::Vector2f(n.circle.getPosition().x - (stream.str().length() - 1) / 2 * mText.getCharacterSize(), n.circle.getPosition().y));
		mWindow.draw(n.circle);
		mWindow.draw(mText);
		ImGui::Begin("TESTESTSETSETSET");
		ImGui::Text("%s", mText.getString());
		ImGui::End();
	}

	mGUI.Render(mWindow);
	ImGui::SFML::Render(mWindow);
	mWindow.display();
}