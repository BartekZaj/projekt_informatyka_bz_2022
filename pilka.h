#pragma once
#include <SFML/Graphics.hpp>

class pilka
{

public:
	pilka(float x_in, float y_in);
	void przesun(float x_in, float y_in);
	sf::Sprite getPilka()
	{
		return pSprite;
	}
	sf::Vector2f getposycjapilka() 
	{
		return pSprite.getPosition(); 
	}
	int zyciepodloga=3;
	void sprawdzKolizjeSciany();
	void animuj();
	void przegrana();
	void wyswietlpilka(sf::RenderWindow& window);
	void wyswietlprzegrana(sf::RenderWindow& window);
	int koniec = 0;
	float xVel = 1, yVel = 1.5;
	int zyciail;
	void zyciadol()
	{
		if(zyciail>=1)
		zyciail--;
	}
	void napiszzycia();
	sf::Sprite pSprite;
	float left();
	float right();
	float top();
	float bottom();
private:
	sf::Vector2f position;
	sf::Texture tekstura;
	sf::Text zycia;
	sf::Font font;
	sf::Text gameover0;
	sf::Text gameover1;
};

