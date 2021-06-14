#include "player.h"


Cialo::Cialo(sf::Texture* texture, float speed, float jumpHeight)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;

	faceRight = true;

	body.setSize(sf::Vector2f(80.0f, 80.0f));
	body.setPosition(500.0f, 128.0f);
	body.setOrigin(35.0f, 35.0f);
	body.setTexture(texture);

}

Cialo::~Cialo()
{

}
//pobieram znaki z klawiatury ktore beda odpowiadaly poruszaniu sie playera, warunkujê jaka predkosc ma osiagnac player w danych kierunkach
void Cialo::update1(float deltaTime)
{
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = speed;
	}
	if (body.getPosition().y + body.getSize().y <= GroundHeight)
	{
		velocity.y += 981.0f * deltaTime;
	}
	else
	{
		body.setPosition(body.getPosition().x, GroundHeight - body.getSize().y);
		velocity.y = 0;
	}


	body.move(velocity * deltaTime);
}


void Cialo::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Cialo::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//collision on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//collision on the bottom
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//collision on the top
		velocity.y = 0.0f;
	}
}