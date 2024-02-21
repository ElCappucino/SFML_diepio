#pragma once

#include "game.h"
class GUI {

private:
	GameObj* gameobject;
	
	sf::Font font;
	sf::RectangleShape HpBarBack;
	sf::RectangleShape HpBarInside;
	float hpBarMaxWidth;
	float percent;
	void initHPBar();

public:
	int flag;

	GUI();
	~GUI();

	void ObjectSetup(GameObj* player);
	void Update(const float& dt);

	void UpdateHPBar();
	
	void renderHPBar();

	void render();

	float GetPercent();

	GameObj* GetGameObj();
};