#pragma once
#include <SFML/Graphics.hpp>
class opcje
{
public:
	opcje(float width, float height);
	void goraop();
	void dolop();
	void prawoop();
	void lewoop();
	int wiersz;
	int wybortr;
	int wybortla;
	int wyborster;
	int kliktr()
	{
		return wybortr;
	}
	int kliktla()
	{
		return wybortla;
	}
	int klikster()
	{
		return wyborster;
	}
	void wyswietlopcje(sf::RenderWindow& window);

private:
	sf::Font font;
	sf::Text trudnosc[2];
	sf::Text pytanietr;
	sf::Text pytanieotlo;
	sf::Text rodzajtla[3];
	sf::Text sterowanie[2];
	sf::Text pytanieoster;
	sf::Text tytulopcje;
	sf::Text tlumaczenie;

	sf::RectangleShape guziktr0;
	sf::RectangleShape guziktr1;
	sf::RectangleShape guziktrtlo0;
	sf::RectangleShape guziktrtlo1;
	sf::RectangleShape pytanietrtlo;
	sf::RectangleShape guzikotlo0;
	sf::RectangleShape guzikotlo1;
	sf::RectangleShape guzikotlo2;
	sf::RectangleShape guzikotlotlo0;
	sf::RectangleShape guzikotlotlo1;
	sf::RectangleShape guzikotlotlo2;
	sf::RectangleShape pytanieotlotlo;
	sf::RectangleShape guzikster0;
	sf::RectangleShape guzikster1;
	sf::RectangleShape guzikstertlo0;
	sf::RectangleShape guzikstertlo1;
	sf::RectangleShape pytaniestertlo;
};

