#include "paletka.h"
 
paletka::paletka(float x_in,float y_in)
{
	position.x = x_in;
	position.y = y_in;

	startposition.x = x_in;
	startposition.y = y_in;

	paletka0.setFillColor(sf::Color(157, 114, 200));
	paletka0.setSize(sf::Vector2f(150, 20));
	paletka0.setPosition(position);

}

void paletka::animujpaletke(float x_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	paletka0.move(pos);
	position = paletka0.getPosition();
}

void paletka::sprawdzKolizjeSciany()
{
	if (position.x <= 110 )
		position.x=110;
	if (position.x >= 940)
		position.x = 940;
	paletka0.setPosition(position);
}

void paletka::resetujpaletke()
{
	paletka0.setPosition(startposition);
}

void paletka::wyswietlpaletka(sf::RenderWindow& window)
{
	window.draw(paletka0);
}
