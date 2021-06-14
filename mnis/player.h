#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "animacja.h"

class Cialo
{
public:
	Cialo(sf::Texture* texture, float speed, float jumpHeight);
	~Cialo();

	void update1(float deltaTime);
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
		sf::RectangleShape body;
private:
	
	
	float speed;
	bool faceRight;
	int GroundHeight=400;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};
