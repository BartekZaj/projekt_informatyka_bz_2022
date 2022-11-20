# projekt_informatyka_bz_2022
 //Pilka odbijajaca sie od ruchomego podloza przesuwanego przez uzytkownika. Pilka trafia w obiekty umieszczone w okreslonym miejscu scenerii.
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>

class Pilka
{
private:
	sf::Vector2f position;
	float xVel = 1, yVel = 1.7;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f rozmiar_okna;
public:
	Pilka(float x_in, float y_in, float o, float i)
	{
		position.x = x_in;
		position.y = y_in;
		rozmiar_okna.x = o;
		rozmiar_okna.y = i;
		tekstura.loadFromFile("pilka.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);
	}
	void przesun(float x_in, float y_in);
	sf::Sprite getPilka()
	{
		return pSprite;
	}
	void sprawdzKolizjeSciany();
	void animuj();
};
void Pilka::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	pSprite.move(pos);
	position = pSprite.getPosition();
}

void Pilka::sprawdzKolizjeSciany()
{
	if (position.x <= 0 || position.x >= rozmiar_okna.x - 100)
		xVel *= -1;

	if (position.y <= 0 || position.y >= rozmiar_okna.y - 100)
		yVel *= -1;

}

void Pilka::animuj()
{
	sprawdzKolizjeSciany();
	przesun(xVel, yVel);
}


int main()
{

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML animation");
	sf::Event event;

	sf::Texture tekstura;
	tekstura.loadFromFile("pilka.png");
	sf::Sprite pokeball(tekstura);
	Pilka pb(40, 10, 1000, 1000);
	sf::Clock zegar;

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Green);
		window.draw(pb.getPilka());
		window.display();
		if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
			pb.animuj();
			zegar.restart();
		}
	}

	return 0;
}
