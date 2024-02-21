#include "game.h"
#include "GUI.h"

void GUI::initHPBar() {
	float width = 50.0f;
	float height = 10.0f;
	hpBarMaxWidth = width;
	this->HpBarBack.setSize(sf::Vector2f(width, height));
	this->HpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->HpBarBack.setPosition(gameobject->position.x, gameobject->position.y + 50.0f);
	this->HpBarInside.setSize(sf::Vector2f(width, height));
	this->HpBarInside.setFillColor(sf::Color(250, 20, 20, 200));
	this->HpBarInside.setPosition(this->HpBarBack.getPosition());
}


GUI::GUI() {
	flag = FLAG_ACTIVE;
	percent = 1;
}
void GUI::ObjectSetup(GameObj* player) {
	this->gameobject = player;
	initHPBar();
}
GUI::~GUI(){}

void GUI::Update(const float& dt)
{
	UpdateHPBar();
}

void GUI::UpdateHPBar()
{
	percent = this->gameobject->lifepoint / this->gameobject->maxlifepoint;
	std::cout << percent << std::endl;
	this->HpBarInside.setSize(
		sf::Vector2f(
			static_cast<float>(std::floor(this->hpBarMaxWidth * percent)),
			this->HpBarInside.getSize().y
		)
	);
}
float GUI::GetPercent() {
	return percent;
}

void GUI::renderHPBar()
{
	window.draw(this->HpBarBack);
	window.draw(this->HpBarInside);
}

void GUI::render()
{
	this->renderHPBar();
}
GameObj* GUI::GetGameObj() {
	return gameobject;
}