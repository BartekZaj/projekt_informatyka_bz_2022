#include "pilka.h"

pilka::pilka(float x_in, float y_in)
{
	position.x = x_in;
	position.y = y_in;
	tekstura.loadFromFile("pilka.png");
	pSprite.setTexture(tekstura);
	pSprite.setPosition(position);
	pSprite.scale(0.5, 0.5);

	font.loadFromFile("arial.ttf");

	zycia.setFillColor(sf::Color::Green);
	zycia.setCharacterSize(20);
	zycia.setFont(font);
	zycia.setPosition(100, 70);
	zyciail = 3;

	gameover0.setFont(font);
	gameover0.setFillColor(sf::Color::Magenta);
	gameover0.setCharacterSize(70);
	gameover0.setString("GAME OVER");
	gameover0.setPosition(90, 80);

	gameover1.setFont(font);
	gameover1.setFillColor(sf::Color::Green);
	gameover1.setCharacterSize(30);
	gameover1.setString("nacisnij ESC by wrocic do menu");
	gameover1.setPosition(90, 230);
}

void pilka::przegrana()
{
	xVel = 0;
	yVel = 0;
}

void pilka::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	pSprite.move(pos);
	position = pSprite.getPosition();
}

void pilka::sprawdzKolizjeSciany()
{
	if (position.x <= 90 || position.x >= 1060)
		xVel *= -1;

	if (position.y <= 90)
		yVel *= -1;
	
	if (position.y >= 660 && zyciepodloga>1)
	{
		yVel *= -1;
		zyciadol();

	}

	if (position.y >= 660 && zyciail == 0)
	{
		przegrana();
		
	}
}

void pilka::animuj()
{
	sprawdzKolizjeSciany();
	przesun(xVel, yVel);
}

float pilka::left() {
	return this->pSprite.getPosition().x;
}

float pilka::right() {
	return this->pSprite.getPosition().x + 40;
}

float pilka::top() {
	return this->pSprite.getPosition().y;
}

float pilka::bottom() {
	return this->pSprite.getPosition().y+20;
}

void pilka::wyswietlpilka(sf::RenderWindow& window)
{
	window.draw(getPilka());
	window.draw(zycia);

}

void pilka::wyswietlprzegrana(sf::RenderWindow& window)
{
	window.draw(gameover0);
	window.draw(gameover1);
}

void::pilka::napiszzycia()
{
	zycia.setString("Zycia : " + std::to_string(zyciail));
}