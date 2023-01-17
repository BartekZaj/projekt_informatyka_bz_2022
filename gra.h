#pragma once
#include <SFML/Graphics.hpp>
class gra
{
public:
	gra(float width, float height);
	int punktyil=0;
	int zyciail=3;
	void wyswietlgra(sf::RenderWindow& window);
	void punktplus()
	{
		punktyil++;
	}
	sf::RectangleShape tlo;
private:
	sf::Font font;
	sf::Text punkty;
	sf::Text zycia;
	sf::Text pauza;

};

