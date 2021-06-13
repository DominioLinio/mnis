#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "animacja.h"

class Cialo
{
public:
	Cialo(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Cialo();

	void update1(float deltaTime);
	void update2(float deltaTime);
	void update3(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	sf::Vector2f GetPosition()
	{
		return body.getPosition();
	}
	Collider GetCollider()
	{
		return Collider(body);
	}

private:
	
	sf::RectangleShape body;
	Animation animation;
	float speed;
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};
