#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "Animation.h"
#include "Player.h"

using namespace std;
int main() {
	
	sf::RenderWindow window(sf::VideoMode(720, 480), "Fight Hard Yeah! Tower Defense Game", sf::Style::Close | sf::Style::Resize);
	//1 old animation sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	//player.setFillColor(sf::Color::Magenta);
	//player.setOrigin(50.0f, 50.0f);
	//1 old animation player.setPosition(206.0f, 206.0f);

	//Main Music Sound
	sf::SoundBuffer mainsoundBuf;
	sf::Sound mainSound;
	std::cout << "loading in background music" << std::endl;
	if (!mainsoundBuf.loadFromFile("Punks.wav"))
		std::cout << "can't open sound file" << std::endl;
	mainSound.setBuffer(mainsoundBuf);
	mainSound.play();

	//Attempting to put the background Image in
	sf::RectangleShape background(sf::Vector2f(720.0f, 480.0f));
	background.setPosition(0.0f, 0.0f);

	//background.setFillColor(sf::Color::Magenta);

	//background.setOrigin(250.0f, 250.0f);
	//background.setPosition(250.0f, 250.0f);
	sf::Texture backgroundImage;
	//backgroundImage.loadFromFile("Woods.png");
	backgroundImage.loadFromFile("mario.png");
	background.setTexture(&backgroundImage);
	

	sf::RectangleShape backgroundTree(sf::Vector2f(150.0f, 150.0f));
	backgroundTree.setPosition(330.0f, 180.0f);

	sf::Texture treeTexture;
	treeTexture.loadFromFile("transparent_tree.png");
	backgroundTree.setTexture(&treeTexture);



	sf::Texture playerTexture;
	playerTexture.loadFromFile("char_sprite_walk2.png");
	//1 old animation player.setTexture(&playerTexture);

	//old animation Animation animation(&playerTexture, sf::Vector2u(3, 9), 0.3f);
	//Player player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f);
	
	//New texture coordinates
	Player player(&playerTexture, sf::Vector2u(3, 2), 0.3f, 100.0f);

	if (!player.soundBuf.loadFromFile("test.wav"))
		std::cout << "can't open sound file" << std::endl;
	player.sound.setBuffer(player.soundBuf);

	float deltaTime = 0.0f;
	sf::Clock clock;

	//putting the character on the screen bound to the box
	/*
	sf::Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 3;
	textureSize.y /= 9;
	player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8, textureSize.x, textureSize.y));
	*/

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{ 
			case sf::Event::Closed:
				window.close();
				break;
			/*case sf::Event::Resized:
				//std::cout << "New window width " << evnt.size.width << "New window height " << evnt.size.height << std::endl;
				printf("New window width: %i New window height: %i \n", evnt.size.width, evnt.size.height);
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128)
				{
					printf("%c", evnt.text.unicode);
				}
			*/
			}
			/*
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
			*/
		}
		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.f, 0.1f);
		}
		*/
		/*
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		}
		*/
		//old animation animation.Update(0, deltaTime, false);
		//player.setTextureRect(animation.uvRect);

		

		player.Update(deltaTime);


		window.clear(sf::Color(125, 125, 125));
		window.draw(background);

		//window.clear();
		player.Draw(window);
		//window.draw(player);
		window.draw(backgroundTree);

		window.display();

		}

		return 0;
}
