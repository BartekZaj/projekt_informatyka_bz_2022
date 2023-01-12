#include "menu.h"
#include <locale.h>


menu::menu()
{
	setlocale(LC_CTYPE, "Polish");
	
	font.loadFromFile("arial.ttf");

	tytul.setFont(font);
	tytul.setCharacterSize(70);
	tytul.setFillColor(sf::Color::Magenta);
	tytul.setPosition(300, 80);
	tytul.setString("ARCANOIDA 9000");

	pozycjaM[0].setFont(font);
	pozycjaM[0].setCharacterSize(50);
	pozycjaM[0].setPosition(480, 200);
	pozycjaM[0].setFillColor(sf::Color::Red);
	pozycjaM[0].setString("Zacznij Gre");
	guzik0.setPosition(470, 200);
	guzik0.setFillColor(sf::Color(0, 255, 255));
	guzik0.setSize(sf::Vector2f (280, 70));
	guziktlo0.setPosition(470, 200);
	guziktlo0.setFillColor(sf::Color(66, 120, 205));
	guziktlo0.setSize(sf::Vector2f(300, 90));

	pozycjaM[1].setFont(font);
	pozycjaM[1].setCharacterSize(50);
	pozycjaM[1].setPosition(480, 300);
	pozycjaM[1].setFillColor(sf::Color::Red);
	pozycjaM[1].setString("Wyniki");
	guzik1.setPosition(470, 300);
	guzik1.setFillColor(sf::Color(0, 255, 255));
	guzik1.setSize(sf::Vector2f(280, 70));
	guziktlo1.setPosition(470, 300);
	guziktlo1.setFillColor(sf::Color(66, 120, 205));
	guziktlo1.setSize(sf::Vector2f(300, 90));

	pozycjaM[2].setFont(font);
	pozycjaM[2].setCharacterSize(50);
	pozycjaM[2].setPosition(480, 400);
	pozycjaM[2].setFillColor(sf::Color::Red);
	pozycjaM[2].setString("Opcje");
	guzik2.setPosition(470, 400);
	guzik2.setFillColor(sf::Color(0, 255, 255));
	guzik2.setSize(sf::Vector2f(280, 70));
	guziktlo2.setPosition(470, 400);
	guziktlo2.setFillColor(sf::Color(66, 120, 205));
	guziktlo2.setSize(sf::Vector2f(300, 90));

	pozycjaM[3].setFont(font);
	pozycjaM[3].setCharacterSize(50);
	pozycjaM[3].setPosition(480, 500);
	pozycjaM[3].setFillColor(sf::Color::Red);
	pozycjaM[3].setString("Pomoc");
	guzik3.setPosition(470, 500);
	guzik3.setFillColor(sf::Color(0, 255, 255));
	guzik3.setSize(sf::Vector2f(280, 70));
	guziktlo3.setPosition(470, 500);
	guziktlo3.setFillColor(sf::Color(66, 120, 205));
	guziktlo3.setSize(sf::Vector2f(300, 90));

	pozycjaM[4].setFont(font);
	pozycjaM[4].setCharacterSize(50);
	pozycjaM[4].setPosition(480, 600);
	pozycjaM[4].setFillColor(sf::Color::Red);
	pozycjaM[4].setString("Wyjscie");
	guzik4.setPosition(470, 600);
	guzik4.setFillColor(sf::Color(0, 255, 255));
	guzik4.setSize(sf::Vector2f(280, 70));
	guziktlo4.setPosition(470, 600);
	guziktlo4.setFillColor(sf::Color(66, 120, 205));
	guziktlo4.setSize(sf::Vector2f(300, 90));
}

void menu::wyswietl(sf::RenderWindow & window)
{
	window.draw(guziktlo0);
	window.draw(guziktlo1);
	window.draw(guziktlo2);
	window.draw(guziktlo3);
	window.draw(guziktlo4);
	window.draw(guzik0);
	window.draw(guzik1);
	window.draw(guzik2);
	window.draw(guzik3);
	window.draw(guzik4);
	window.draw(pozycjaM[0]);
	window.draw(pozycjaM[1]);
	window.draw(pozycjaM[2]);
	window.draw(pozycjaM[3]);
	window.draw(pozycjaM[4]);
	window.draw(tytul);

}


