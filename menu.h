#pragma once
#include <SFML/Graphics.hpp>
class menu
{
public:
	menu(float width, float height);
	void wyzej();
	void nizej();
	int wybor;
	int klik()
	{
		return wybor;
	}
	void wyswietlmenu (sf::RenderWindow& window);


private:

	sf::Font font;
	sf::Text pozycjaM[5];
	sf::Text tytul;

	sf::RectangleShape guzik0;
	sf::RectangleShape guzik1;
	sf::RectangleShape guzik2;
	sf::RectangleShape guzik3;
	sf::RectangleShape guzik4;

	sf::RectangleShape guziktlo0;
	sf::RectangleShape guziktlo1;
	sf::RectangleShape guziktlo2;
	sf::RectangleShape guziktlo3;
	sf::RectangleShape guziktlo4;
};

