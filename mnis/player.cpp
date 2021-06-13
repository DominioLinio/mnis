#include "player.h"
#include "animacja.h"

Cialo::Cialo(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;

	faceRight = true;

	body.setSize(sf::Vector2f(80.0f, 112.0f));
	body.setPosition(128.0f, 128.0f);
	body.setOrigin(40.0f, 56.0f);
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
	velocity.y += 981.0f * deltaTime;


	body.move(velocity * deltaTime);
}

void Cialo::update2(float deltaTime)
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
	
	velocity.y += 981.0f * deltaTime;
	body.move(velocity * deltaTime);
}

void Cialo::update3(float deltaTime)
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
	// warunkuje kiedy player moze skakac, czyli jezeli nacisnieta jest spacja, oraz do poki canJump bedzie prawda
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);

	}
	velocity.y += 981.0f * deltaTime;
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