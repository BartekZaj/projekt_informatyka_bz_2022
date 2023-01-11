#pragma once
#include <SFML/Graphics.hpp>
class menu
{
public:
	menu();
	void wyzej();
	void nizej();
	int wybor = 0;
	int klik()
	{
		return wybor;
	}
	void wyswietl (sf::RenderWindow& window);
	sf::RectangleShape guzik0;

private:
	sf::Font font;
	sf::Text pozycjaM[5];

};

