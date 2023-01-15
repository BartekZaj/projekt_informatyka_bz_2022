#include "zapytanie.h"
#include <locale.h>

zapytanie::zapytanie(float width, float height)
{
	setlocale(LC_CTYPE, "Polish");
	font.loadFromFile("arial.ttf");
	
	pytanie.setFont(font);
	pytanie.setCharacterSize(30);
	pytanie.setFillColor(sf::Color::Magenta);
	pytanie.setPosition(200,80);
	pytanie.setString("Czy na pewno");
	pytanie2.setFont(font);
	pytanie2.setCharacterSize(30);
	pytanie2.setFillColor(sf::Color::Magenta);
	pytanie2.setPosition(200, 120);
	pytanie2.setString("chcesz wyjsc?");
	pytanietlo.setPosition(150, 80);
	pytanietlo.setFillColor(sf::Color(120, 0, 180));
	pytanietlo.setSize(sf::Vector2f(300, 90));


	tekstzap[0].setFont(font);
	tekstzap[0].setCharacterSize(50);
	tekstzap[0].setFillColor(sf::Color::Red);
	tekstzap[0].setPosition(100, 200);
	tekstzap[0].setString("Tak");
	guzikzap0.setPosition(90, 200);
	guzikzap0.setFillColor(sf::Color(0, 255, 255));
	guzikzap0.setSize(sf::Vector2f(120, 90));
	guzikzaptlo0.setPosition(90, 200);
	guzikzaptlo0.setFillColor(sf::Color(66, 120, 205));
	guzikzaptlo0.setSize(sf::Vector2f(120, 90));

	tekstzap[1].setFont(font);
	tekstzap[1].setCharacterSize(50);
	tekstzap[1].setFillColor(sf::Color::Red);
	tekstzap[1].setPosition(400, 200);
	tekstzap[1].setString("Nie");
	guzikzap1.setPosition(390, 200);
	guzikzap1.setFillColor(sf::Color(0, 255, 255));
	guzikzap1.setSize(sf::Vector2f(100, 70));
	guzikzaptlo1.setPosition(390, 200);
	guzikzaptlo1.setFillColor(sf::Color(66, 120, 205));
	guzikzaptlo1.setSize(sf::Vector2f(120, 90));

	wyborzap = 0;
}

void zapytanie::wyswietlzap(sf::RenderWindow & window)
{
	window.draw(pytanietlo);
	window.draw(pytanie);
	window.draw(pytanie2);
	window.draw(guzikzaptlo0);
	window.draw(guzikzap0);
	window.draw(tekstzap[0]);
	window.draw(guzikzaptlo1);
	window.draw(guzikzap1);
	window.draw(tekstzap[1]);
}

void zapytanie::prawozap()
{
	guzikzap0.setSize(sf::Vector2f(100, 70));
	guzikzap1.setSize(sf::Vector2f(120, 90));
	wyborzap=1;
}

void zapytanie::lewozap()
{
	guzikzap1.setSize(sf::Vector2f(100, 70));
	guzikzap0.setSize(sf::Vector2f(120, 90));
	wyborzap=0;
}

