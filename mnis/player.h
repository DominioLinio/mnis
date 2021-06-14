#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"


class Cialo
{
public:
	Cialo(sf::Texture* texture, float speed, float jumpHeight);
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
		sf::RectangleShape body;
		sf::Vector2f velocity;
private:
	
	
	float speed;
	bool faceRight;
	int GroundHeight=400;

	
	bool canJump;
	float jumpHeight;
};
