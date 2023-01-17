#include "pauza.h"

pauza::pauza(float width, float height)
{
	font.loadFromFile("arial.ttf");
	tytul.setFont(font);
	tytul.setCharacterSize(50);
	tytul.setFillColor(sf::Color::Magenta);
	tytul.setPosition(200, 20);
	tytul.setString("PAUZA");

	reset0.setFont(font);
	reset0.setCharacterSize(17);
	reset0.setFillColor(sf::Color::Green);
	reset0.setPosition(60, 110);
	reset0.setString("W celu zrestartowania gry nalezy nacisnac R");
	kropka0.setFillColor(sf::Color::Magenta);
	kropka0.setRadius(10);
	kropka0.setPosition(30, 110);

	sterowanie0.setFont(font);
	sterowanie0.setCharacterSize(17);
	sterowanie0.setFillColor(sf::Color::Green);
	sterowanie0.setPosition(60, 140);
	sterowanie0.setString("Sterowanie paletka domyslnie odbywa sie za pomoca A i D:");

	sterowanie1.setFont(font);
	sterowanie1.setCharacterSize(17);
	sterowanie1.setFillColor(sf::Color::Green);
	sterowanie1.setPosition(60, 170);
	sterowanie1.setString("Zmiana sterowania mozliwa jest w menu opcji");

	kropka1.setFillColor(sf::Color::Magenta);
	kropka1.setRadius(10);
	kropka1.setPosition(30, 140);

	celgry0.setFont(font);
	celgry0.setCharacterSize(17);
	celgry0.setFillColor(sf::Color::Green);
	celgry0.setPosition(60, 200);
	celgry0.setString("Celem gry jest poruszanie paletka tak aby odbic pilke");

	celgry1.setFont(font);
	celgry1.setCharacterSize(17);
	celgry1.setFillColor(sf::Color::Green);
	celgry1.setPosition(60, 230);
	celgry1.setString("Odbita pilka bedzie uderzac w bloczki, ktore po uderzeniu znikna");

	celgry2.setFont(font);
	celgry2.setCharacterSize(17);
	celgry2.setFillColor(sf::Color::Green);
	celgry2.setPosition(60, 260);
	celgry2.setString("Gracz wygrywa kiedy na planszy nie zostanie zadny bloczek");

	celgry3.setFont(font);
	celgry3.setCharacterSize(17);
	celgry3.setFillColor(sf::Color::Green);
	celgry3.setPosition(60, 290);
	celgry3.setString("Kiedy pilka dotknie podlogi gracz traci zycie");

	celgry4.setFont(font);
	celgry4.setCharacterSize(17);
	celgry4.setFillColor(sf::Color::Green);
	celgry4.setPosition(60, 320);
	celgry4.setString("Gracz przegrywa kiedy straci wszystkie zycia");

	kropka2.setFillColor(sf::Color::Magenta);
	kropka2.setRadius(10);
	kropka2.setPosition(30, 200);

	wznowienie.setFont(font);
	wznowienie.setCharacterSize(17);
	wznowienie.setFillColor(sf::Color::Green);
	wznowienie.setPosition(60, 350);
	wznowienie.setString("W celu wznowienia gry nalezy nacisnac ESC");

	kropka3.setFillColor(sf::Color::Magenta);
	kropka3.setRadius(10);
	kropka3.setPosition(30, 350);



}

void pauza::wyswietlpauza(sf::RenderWindow& window)
{
	window.draw(tytul);



	window.draw(kropka0);
	window.draw(reset0);

	window.draw(kropka1);
	window.draw(sterowanie0);
	window.draw(sterowanie1);

	window.draw(kropka2);
	window.draw(celgry0);
	window.draw(celgry1);
	window.draw(celgry2);
	window.draw(celgry3);
	window.draw(celgry4);

	window.draw(kropka3);
	window.draw(wznowienie);

}