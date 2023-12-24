#include "StackManager.h"

StackManager::StackManager(const sf::Vector2f& location) 
	: mOffset(location)
{
	mFont.loadFromFile("assets/Roboto-Regular.ttf");
	mFont.setSmooth(true);
	mText.setFont(mFont);
	mText.setFillColor(sf::Color::Black);
	mText.setCharacterSize(18.f);
}

void StackManager::Push(const std::string& data) 
{
	Frame f;
	f.rect.setSize(sf::Vector2f(100.f, 70.f));
	f.rect.setOrigin(f.rect.getSize() / 2.f);
	f.rect.setOutlineColor(sf::Color::Black);
	f.rect.setOutlineThickness(1.f);
	f.rect.setPosition(sf::Vector2f(mOffset.x, mOffset.y + (mStack.size() * -70.f - mStack.size())));
	f.data = data;

	mStack.push_back(f);
}

void StackManager::Pop() 
{
	if (!mStack.empty())
		mStack.pop_back();
}

const std::string StackManager::Peek() 
{
	return mStack.empty() ? "NULL" : mStack.back().data;
}

void StackManager::Render(sf::RenderWindow& window) 
{
	for (Frame f : mStack) 
	{
		mText.setString(f.data);
		mText.setPosition(f.rect.getPosition().x - 4.f - (f.data.size() * mText.getCharacterSize()) / 4.f, f.rect.getPosition().y - mText.getCharacterSize() / 2.f);

		window.draw(f.rect);
		window.draw(mText);
	}
}