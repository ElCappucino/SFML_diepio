#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
public:
	Button();
	Button(std::string _text, sf::Vector2f _size, int charSize, sf::Color _bgColor, sf::Color _textColor);
	void setFont(sf::Font& font);
	void setBackColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setPosition(sf::Vector2f pos);
	void drawTo(sf::RenderWindow& window);
	bool isMouseOver(sf::RenderWindow& window);
private:
	sf::RectangleShape button;
	sf::Text text;
};