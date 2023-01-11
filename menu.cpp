#include "menu.h"
#include <locale.h>


menu::menu()
{
	setlocale(LC_CTYPE, "Polish");
	
	font.loadFromFile("arial.ttf");
	pozycjaM[0].setFont(font);
	pozycjaM[0].setCharacterSize(50);
	pozycjaM[0].setPosition(490, 200);
	pozycjaM[0].setFillColor(sf::Color::Red);
	pozycjaM[0].setString("Zacznij Grê");
	guzik0.setPosition(480, 200);
	guzik0.setFillColor(sf::Color(0, 255, 255));
	guzik0.setSize(sf::Vector2f (280, 70));

}

void menu::wyswietl(sf::RenderWindow & window)
{
	window.draw(guzik0);
	window.draw(pozycjaM[0]);
	
}

