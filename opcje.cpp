#include "opcje.h"
#include <locale.h>


opcje::opcje(float width, float height)
{
	setlocale(LC_CTYPE, "Polish");
	font.loadFromFile("arial.ttf");

	tytulopcje.setFont(font);
	tytulopcje.setCharacterSize(70);
	tytulopcje.setFillColor(sf::Color::Magenta);
	tytulopcje.setPosition(480, 50);
	tytulopcje.setString("OPCJE");

	tlumaczenie.setFont(font);
	tlumaczenie.setCharacterSize(30);
	tlumaczenie.setFillColor(sf::Color::Green);
	tlumaczenie.setPosition(400, 140);
	tlumaczenie.setString("Zielony kolor = Obecny wybor");

	pytanietr.setFont(font);
	pytanietr.setCharacterSize(30);
	pytanietr.setFillColor(sf::Color::Magenta);
	pytanietr.setPosition(420, 200);
	pytanietr.setString("Wybierz Poziom Trudnosci");
	pytanietrtlo.setPosition(410, 200);
	pytanietrtlo.setFillColor(sf::Color(120, 0, 180));
	pytanietrtlo.setSize(sf::Vector2f(380, 40));


	trudnosc[0].setFont(font);
	trudnosc[0].setCharacterSize(40);
	trudnosc[0].setFillColor(sf::Color::Green);
	trudnosc[0].setPosition(420, 255);
	trudnosc[0].setString("Latwy");
	guziktr0.setPosition(400, 255);
	guziktr0.setFillColor(sf::Color(0, 255, 255));
	guziktr0.setSize(sf::Vector2f(170, 80));
	guziktrtlo0.setPosition(400, 255);
	guziktrtlo0.setFillColor(sf::Color(66, 120, 205));
	guziktrtlo0.setSize(sf::Vector2f(170, 80));

	trudnosc[1].setFont(font);
	trudnosc[1].setCharacterSize(40);
	trudnosc[1].setFillColor(sf::Color::Red);
	trudnosc[1].setPosition(650, 255);
	trudnosc[1].setString("Trudny");
	guziktr1.setPosition(630, 255);
	guziktr1.setFillColor(sf::Color(0, 255, 255));
	guziktr1.setSize(sf::Vector2f(150, 60));
	guziktrtlo1.setPosition(630, 255);
	guziktrtlo1.setFillColor(sf::Color(66, 120, 205));
	guziktrtlo1.setSize(sf::Vector2f(170, 80));

	pytanieotlo.setFont(font);
	pytanieotlo.setCharacterSize(30);
	pytanieotlo.setFillColor(sf::Color::Magenta);
	pytanieotlo.setPosition(420, 350);
	pytanieotlo.setString("Wybierz Tlo Rozgrywki");
	pytanieotlotlo.setPosition(410, 350);
	pytanieotlotlo.setFillColor(sf::Color(120, 0, 180));
	pytanieotlotlo.setSize(sf::Vector2f(380, 40));


	rodzajtla[0].setFont(font);
	rodzajtla[0].setCharacterSize(40);
	rodzajtla[0].setFillColor(sf::Color::Green);
	rodzajtla[0].setPosition(220, 400);
	rodzajtla[0].setString("Cyan");
	guzikotlo0.setPosition(200, 400);
	guzikotlo0.setFillColor(sf::Color(0, 255, 255));
	guzikotlo0.setSize(sf::Vector2f(240, 60));
	guzikotlotlo0.setPosition(200, 400);
	guzikotlotlo0.setFillColor(sf::Color(66, 120, 205));
	guzikotlotlo0.setSize(sf::Vector2f(260, 80));


	rodzajtla[1].setFont(font);
	rodzajtla[1].setCharacterSize(40);
	rodzajtla[1].setFillColor(sf::Color::Red);
	rodzajtla[1].setPosition(495, 400);
	rodzajtla[1].setString("Pomarancz");
	guzikotlo1.setPosition(475, 400);
	guzikotlo1.setFillColor(sf::Color(0, 255, 255));
	guzikotlo1.setSize(sf::Vector2f(240, 60));
	guzikotlotlo1.setPosition(475, 400);
	guzikotlotlo1.setFillColor(sf::Color(66, 120, 205));
	guzikotlotlo1.setSize(sf::Vector2f(260, 80));


	rodzajtla[2].setFont(font);
	rodzajtla[2].setCharacterSize(40);
	rodzajtla[2].setFillColor(sf::Color::Red);
	rodzajtla[2].setPosition(780, 400);
	rodzajtla[2].setString("Rozowy");
	guzikotlo2.setPosition(750, 400);
	guzikotlo2.setFillColor(sf::Color(0, 255, 255));
	guzikotlo2.setSize(sf::Vector2f(240, 60));
	guzikotlotlo2.setPosition(750, 400);
	guzikotlotlo2.setFillColor(sf::Color(66, 120, 205));
	guzikotlotlo2.setSize(sf::Vector2f(260, 80));


	pytanieoster.setFont(font);
	pytanieoster.setCharacterSize(30);
	pytanieoster.setFillColor(sf::Color::Magenta);
	pytanieoster.setPosition(420, 500);
	pytanieoster.setString("Wybierz Sterowanie");
	pytaniestertlo.setPosition(410, 500);
	pytaniestertlo.setFillColor(sf::Color(120, 0, 180));
	pytaniestertlo.setSize(sf::Vector2f(380, 40));


	sterowanie[0].setFont(font);
	sterowanie[0].setCharacterSize(40);
	sterowanie[0].setFillColor(sf::Color::Green);
	sterowanie[0].setPosition(430,550);
	sterowanie[0].setString("A i D");
	guzikster0.setPosition(400, 550);
	guzikster0.setFillColor(sf::Color(0, 255, 255));
	guzikster0.setSize(sf::Vector2f(150, 60));
	guzikstertlo0.setPosition(400, 550);
	guzikstertlo0.setFillColor(sf::Color(66, 120, 205));
	guzikstertlo0.setSize(sf::Vector2f(170, 80));


	sterowanie[1].setFont(font);
	sterowanie[1].setCharacterSize(40);
	sterowanie[1].setFillColor(sf::Color::Red);
	sterowanie[1].setPosition(635, 550);
	sterowanie[1].setString("Strzalki");
	guzikster1.setPosition(630, 550);
	guzikster1.setFillColor(sf::Color(0, 255, 255));
	guzikster1.setSize(sf::Vector2f(150, 60));
	guzikstertlo1.setPosition(630, 550);
	guzikstertlo1.setFillColor(sf::Color(66, 120, 205));
	guzikstertlo1.setSize(sf::Vector2f(170, 80));

	wyborster;
	wybortla;
	wybortr;
	wiersz;

}

void opcje::wyswietlopcje(sf::RenderWindow& window)
{
	window.draw(tytulopcje);
	window.draw(tlumaczenie);
	window.draw(pytanietrtlo);
	window.draw(pytanietr);
	window.draw(guziktrtlo0);
	window.draw(guziktr0);
	window.draw(trudnosc[0]);
	window.draw(guziktrtlo1);
	window.draw(guziktr1);
	window.draw(trudnosc[1]);
	window.draw(pytanieotlotlo);
	window.draw(pytanieotlo);
	window.draw(guzikotlotlo0);
	window.draw(guzikotlo0);
	window.draw(rodzajtla[0]);
	window.draw(guzikotlotlo1);
	window.draw(guzikotlo1);
	window.draw(rodzajtla[1]);
	window.draw(guzikotlotlo2);
	window.draw(guzikotlo2);
	window.draw(rodzajtla[2]);
	window.draw(pytaniestertlo);
	window.draw(pytanieoster);
	window.draw(guzikstertlo0);
	window.draw(guzikster0);
	window.draw(sterowanie[0]);
	window.draw(guzikstertlo1);
	window.draw(guzikster1);
	window.draw(sterowanie[1]);

}

void opcje::goraop()
{
	if (wiersz - 1 >= 0)
	{
		switch (wiersz)
		{
		case 1:
			guziktr0.setSize(sf::Vector2f(170, 80));
			guzikotlo0.setSize(sf::Vector2f(240, 60));
			guzikotlo1.setSize(sf::Vector2f(240, 60));
			guzikotlo2.setSize(sf::Vector2f(240, 60));
			wiersz=0;
			wybortr = 0;
			break;
		case 2:
			guzikotlo0.setSize(sf::Vector2f(260, 80));
			guzikster0.setSize(sf::Vector2f(150, 60));
			guzikster1.setSize(sf::Vector2f(150, 60));
			wiersz=1;
			wybortla = 0;
			break;
		}
	}

}

void opcje::dolop()
{
	if (wiersz + 1 <= 2)
	{
		switch (wiersz)
		{
		case 0:
			guzikotlo0.setSize(sf::Vector2f(260, 80));
			guziktr0.setSize(sf::Vector2f(150, 60));
			guziktr1.setSize(sf::Vector2f(150, 60));
			wiersz=1;
			wybortla = 0;
			break;
		case 1:
			guzikotlo0.setSize(sf::Vector2f(240, 60));
			guzikotlo1.setSize(sf::Vector2f(240, 60));
			guzikotlo2.setSize(sf::Vector2f(240, 60));
			guzikster0.setSize(sf::Vector2f(170, 80));
			wiersz=2;
			wyborster = 0;
			break;
		}
	}

}

void opcje::prawoop()
{
	switch (wiersz)
	{
	case 0:
			guziktr0.setSize(sf::Vector2f(150, 60));
			guziktr1.setSize(sf::Vector2f(170, 80));
			wybortr = 1;
			break;
	case 1:
		switch (wybortla)
		{
		case 0:
			guzikotlo0.setSize(sf::Vector2f(240, 60));
			guzikotlo1.setSize(sf::Vector2f(260, 80));
			wybortla = 1;
			break;
		case 1:
			guzikotlo1.setSize(sf::Vector2f(240, 60));
			guzikotlo2.setSize(sf::Vector2f(260, 80));
			wybortla = 2;
			break;
		}
		break;
	case 2:
			guzikster0.setSize(sf::Vector2f(150, 60));
			guzikster1.setSize(sf::Vector2f(170, 80));
			wyborster = 1;
			break;	
	}
}

void opcje::lewoop()
{
	switch (wiersz)
	{	
	case 0:
			guziktr1.setSize(sf::Vector2f(150, 60));
			guziktr0.setSize(sf::Vector2f(170, 80));
			wybortr = 0;
			break;
	case 1:
		switch (wybortla)
		{
		case 2:
			guzikotlo2.setSize(sf::Vector2f(240, 60));
			guzikotlo1.setSize(sf::Vector2f(260, 80));
			wybortla = 1;
			break;
		case 1:
			guzikotlo1.setSize(sf::Vector2f(240, 60));
			guzikotlo0.setSize(sf::Vector2f(260, 80));
			wybortla = 0;
			break;
		}
		break;
	case 2:	
			guzikster1.setSize(sf::Vector2f(150, 60));
			guzikster0.setSize(sf::Vector2f(170, 80));
			wyborster = 0;
			break;	
	}
}