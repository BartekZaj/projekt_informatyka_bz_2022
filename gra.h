#pragma once
#include <SFML/Graphics.hpp>
class gra
{
public:
	gra(float width, float height);
	int punktyil=0;
	int zyciail = 0;
	int zyciepodloga = 3;
	void przesun(float x_in, float y_in);
	void wyswietlinterfejs(sf::RenderWindow& window);
	void wyswietlprzegrana(sf::RenderWindow& window);
	void wyswietlwygrana(sf::RenderWindow& widnow);
	void wyswietlbloki(sf::RenderWindow& window);
	int koniec = 0;
	int trudnoscpunkty = 1;
	void punktplus()
	{
		punktyil = punktyil + (10 * trudnoscpunkty);
	}
	void zyciadol()
	{
		if (zyciail >= 1)
			zyciail--;
	}
	void animuj();
	void ruchpaletkiprawo();
	void ruchpaletkilewo();
	void przegrana();
	void sprawdzKolizjeScianyPaletki();
	void sprawdzKolizjeScianyPilki();
	void odbijpaletke();
	void odbijblok();
	void napiszzycia();
	void napiszpunkty();
	float xVelpilki = 1, yVelpilki = 1.5;
	sf::RectangleShape tlo;
	sf::Sprite pilka;
	sf::Sprite paletka;
	sf::Vector2f position;
	sf::Vector2f position2;

private:

	sf::Font font;
	sf::Text gameover0;
	sf::Text gameover1;

	sf::Text gratulacje;
	sf::Text wygrana0;
	sf::Text wygrana1;
	sf::Text wygrana2;

	sf::Text punkty;
	sf::Text zycia;
	sf::Text pauza;

	sf::Texture teksturapilki;
	sf::Texture teksturapaletki;
	sf::Texture teksturabloki;

	sf::Sprite blok[50];

};

