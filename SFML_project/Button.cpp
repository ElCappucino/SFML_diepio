#include "game.h"
#include <iostream>
#include "Button.h"
#include "SFML/Graphics.hpp"

Button::Button() { }
Button::Button(std::string _text, sf::Vector2f _size, int charSize, sf::Color _bgColor, sf::Color _textColor) {
	text.setString(_text);
	text.setFillColor(_textColor);
	text.setCharacterSize(charSize);
	button.setSize(_size);
	button.setFillColor(_bgColor);
}
void Button::setFont(sf::Font& font) 
{
	text.setFont(font);
}
void Button::setBackColor(sf::Color color) 
{
	button.setFillColor(color);
}
void Button::setTextColor(sf::Color color) 
{
	text.setFillColor(color);
}
void Button::setPosition(sf::Vector2f pos) 
{
	button.setPosition(pos);

	float xPos = (pos.x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
	float yPos = (pos.y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);
	text.setPosition(xPos, yPos);
}
void Button::drawTo(sf::RenderWindow& window) 
{
	window.draw(button);
	window.draw(text);
}
bool Button::isMouseOver(sf::RenderWindow& window) 
{
	int MouseX = sf::Mouse::getPosition(window).x;
	int MouseY = sf::Mouse::getPosition(window).y;
	int btnPosX = button.getPosition().x;
	int btnPosY = button.getPosition().y;

	float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

	if (MouseX < btnxPosWidth &&
		MouseX > btnPosX &&
		MouseY < btnyPosHeight &&
		MouseY > btnPosY) {
		return true;
	}
	return false;
}