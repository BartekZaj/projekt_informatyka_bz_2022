#pragma once
#include <SFML/Graphics.hpp>
class paletka
{
public:
	paletka(float x_in, float y_in);
	void animujpaletke(float x_in);
	void sprawdzKolizjeSciany();
	void wyswietlpaletka(sf::RenderWindow& window);
	sf::RectangleShape getPaletka()
	{
		return paletka0;
	}
	sf::Vector2f getpozycjapaletka() 
	{
		return paletka0.getPosition();
	}
	sf::RectangleShape paletka0;
	sf::Vector2f position;
	sf::Vector2f startposition;
	void resetujpaletke();


};

