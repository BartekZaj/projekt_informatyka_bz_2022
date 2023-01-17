#pragma once
#include <SFML/Graphics.hpp>
class pauza
{
public:
	pauza(float width, float height);
	void wyswietlpauza(sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text sterowanie0;
	sf::Text sterowanie1;
	
	sf::Text reset0;

	sf::Text celgry0;
	sf::Text celgry1;
	sf::Text celgry2;
	sf::Text celgry3;
	sf::Text celgry4;

	sf::Text tytul;

	sf::CircleShape kropka0;
	sf::CircleShape kropka1;
	sf::CircleShape kropka2;
	sf::CircleShape kropka3;

	sf::Text wznowienie;

};

