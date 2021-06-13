#pragma once
#include <SFML\Graphics.hpp>

class Animation
{
public:
	//konstruktory i destruktory
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();
	//metoda do aktualizowania animacji
	void Update1(int row, float deltaTime, bool faceRight);
	void Update2(int row, float deltaTime, bool faceRight);
	void Update3(int row, float deltaTime, bool faceRight);
public:
	sf::IntRect uvRect;
	void setSmooth(bool smooth);
	//funkcje

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;


	float totalTime;
	float switchTime;

};

