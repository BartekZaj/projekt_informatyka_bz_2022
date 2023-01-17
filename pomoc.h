#pragma once
#include <SFML/Graphics.hpp>
class pomoc
{
public:
	pomoc(float width, float height);
	void wyswietlpomoc(sf::RenderWindow& window);
private:
	sf::Font font;
	sf::Text sterowanie0;
	sf::Text sterowanie1;
	sf::Text sterowanie2;
	sf::Text sterowanie3;
	sf::Text sterowanie4;

	sf::Text pauza0;
	sf::Text pauza1;
	sf::Text pauza2;
	
	sf::Text reset0;
	sf::Text reset1;

	sf::Text celgry0;
	sf::Text celgry1;
	sf::Text celgry2;
	sf::Text celgry3;
	sf::Text celgry4;
	sf::Text celgry5;

	sf::Text tytulpomoc;

	sf::CircleShape kropka0;
	sf::CircleShape kropka1;
	sf::CircleShape kropka2;
	sf::CircleShape kropka3;

};

