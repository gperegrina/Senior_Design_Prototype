#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	//Sound settings
	sf::SoundBuffer soundBuf;
	sf::Sound sound;


private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;



};






