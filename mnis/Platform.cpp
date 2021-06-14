#include "Platform.h"


Block::Block(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}


Block::~Block()
{
}

void Block::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
