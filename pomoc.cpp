#include "pomoc.h"
#include <locale.h>

pomoc::pomoc(float width, float height)
{
	setlocale(LC_CTYPE, "Polish");
	font.loadFromFile("arial.ttf");

	tytulpomoc.setFont(font);
	tytulpomoc.setCharacterSize(70);
	tytulpomoc.setFillColor(sf::Color::Magenta);
	tytulpomoc.setPosition(480, 50);
	tytulpomoc.setString("POMOC");

	sterowanie0.setFont(font);
	sterowanie0.setCharacterSize(30);
	sterowanie0.setFillColor(sf::Color::Magenta);
	sterowanie0.setPosition(150, 140);
	sterowanie0.setString("Sterowanie:");

	sterowanie1.setFont(font);
	sterowanie1.setCharacterSize(20);
	sterowanie1.setFillColor(sf::Color::Green);
	sterowanie1.setPosition(150, 180);
	sterowanie1.setString("Zmiana sterowania mozliwa jest w menu opcji");

	sterowanie2.setFont(font);
	sterowanie2.setCharacterSize(20);
	sterowanie2.setFillColor(sf::Color::Green);
	sterowanie2.setPosition(150, 210);
	sterowanie2.setString("Domyslne sterowanie odbywa sie za pomoca przyciskow A i D ");

	sterowanie3.setFont(font);
	sterowanie3.setCharacterSize(20);
	sterowanie3.setFillColor(sf::Color::Green);
	sterowanie3.setPosition(150, 240);
	sterowanie3.setString("A - Ruch paletki w lewo");

	sterowanie4.setFont(font);
	sterowanie4.setCharacterSize(20);
	sterowanie4.setFillColor(sf::Color::Green);
	sterowanie4.setPosition(450, 240);
	sterowanie4.setString("D - Ruch paletki w prawo");

	kropka0.setFillColor(sf::Color::Magenta);
	kropka0.setRadius(10);
	kropka0.setPosition(110, 150);

	pauza0.setFont(font);
	pauza0.setCharacterSize(30);
	pauza0.setFillColor(sf::Color::Magenta);
	pauza0.setPosition(150, 290);
	pauza0.setString("Pauza");

	pauza1.setFont(font);
	pauza1.setCharacterSize(20);
	pauza1.setFillColor(sf::Color::Green);
	pauza1.setPosition(150, 330);
	pauza1.setString("W celu zapauzowania gry nalezy nacisnac F1");

	pauza2.setFont(font);
	pauza2.setCharacterSize(20);
	pauza2.setFillColor(sf::Color::Green);
	pauza2.setPosition(150, 360);
	pauza2.setString("W celu wznowienia gry nalezy nacisnac ESC");

	kropka1.setFillColor(sf::Color::Magenta);
	kropka1.setRadius(10);
	kropka1.setPosition(110, 300);

	reset0.setFont(font);
	reset0.setCharacterSize(30);
	reset0.setFillColor(sf::Color::Magenta);
	reset0.setPosition(150,400);
	reset0.setString("Reset");

	reset1.setFont(font);
	reset1.setCharacterSize(20);
	reset1.setFillColor(sf::Color::Green);
	reset1.setPosition(150, 440);
	reset1.setString("W celu zrestartowania gry nalezy nacisnac R");

	kropka2.setFillColor(sf::Color::Magenta);
	kropka2.setRadius(10);
	kropka2.setPosition(110, 410);

	celgry0.setFont(font);
	celgry0.setCharacterSize(30);
	celgry0.setFillColor(sf::Color::Magenta);
	celgry0.setPosition(150, 490);
	celgry0.setString("Cel Gry:");

	celgry1.setFont(font);
	celgry1.setCharacterSize(20);
	celgry1.setFillColor(sf::Color::Green);
	celgry1.setPosition(150, 530);
	celgry1.setString("Celem gry jest poruszanie paletka tak aby odbic pilke");

	celgry2.setFont(font);
	celgry2.setCharacterSize(20);
	celgry2.setFillColor(sf::Color::Green);
	celgry2.setPosition(150, 560);
	celgry2.setString("Odbita pilka bedzie uderzac w bloczki, ktore po uderzeniu znikna");

	celgry3.setFont(font);
	celgry3.setCharacterSize(20);
	celgry3.setFillColor(sf::Color::Green);
	celgry3.setPosition(150, 590);
	celgry3.setString("Gracz wygrywa kiedy na planszy nie zostanie zadny bloczek");

	celgry4.setFont(font);
	celgry4.setCharacterSize(20);
	celgry4.setFillColor(sf::Color::Green);
	celgry4.setPosition(150, 620);
	celgry4.setString("Kiedy pilka dotknie podlogi gracz traci zycie");

	celgry5.setFont(font);
	celgry5.setCharacterSize(20);
	celgry5.setFillColor(sf::Color::Green);
	celgry5.setPosition(150, 650);
	celgry5.setString("Gracz przegrywa kiedy straci wszystkie zycia");

	kropka3.setFillColor(sf::Color::Magenta);
	kropka3.setRadius(10);
	kropka3.setPosition(110, 500);
}

void pomoc::wyswietlpomoc(sf::RenderWindow & window)
{
	window.draw(tytulpomoc);

	window.draw(kropka0);
	window.draw(sterowanie0);
	window.draw(sterowanie1);
	window.draw(sterowanie2);
	window.draw(sterowanie3);
	window.draw(sterowanie4);

	window.draw(kropka1);
	window.draw(pauza0);
	window.draw(pauza1);
	window.draw(pauza2);

	window.draw(kropka2);
	window.draw(reset0);
	window.draw(reset1);

	window.draw(kropka3);
	window.draw(celgry0);
	window.draw(celgry1);
	window.draw(celgry2);
	window.draw(celgry3);
	window.draw(celgry4);
	window.draw(celgry5);


}