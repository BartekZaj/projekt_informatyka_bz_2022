#pragma once

#include <SFML/Graphics.hpp>
class zapytanie
{
public:
	zapytanie(float width, float height);
	void prawozap();
	void lewozap();
	int wyborzap;
	int klikzap()
	{
		return wyborzap;
	}
	void wyswietlzap (sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text tekstzap[2];
	sf::Text pytanie;
	sf::Text pytanie2;

	sf::RectangleShape guzikzap0;
	sf::RectangleShape guzikzap1;
	sf::RectangleShape guzikzaptlo0;
	sf::RectangleShape guzikzaptlo1;
	sf::RectangleShape pytanietlo;

};

