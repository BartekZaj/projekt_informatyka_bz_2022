#include "gra.h"

gra::gra(float width, float height)
{
	font.loadFromFile("arial.ttf");

	tlo.setFillColor(sf::Color::Cyan);
	tlo.setPosition(100, 100);
	tlo.setSize(sf::Vector2f(1000, 600));
	
	zycia.setFillColor(sf::Color::Green);
	zycia.setCharacterSize(20);
	zycia.setFont(font);
	zycia.setString("Zycia : " + std::to_string(zyciail));
	zycia.setPosition(100, 70);

	punkty.setFont(font);
	punkty.setCharacterSize(20);
	punkty.setFillColor(sf::Color::Green);
	punkty.setString("Punkty : " + std::to_string(punktyil));
	punkty.setPosition(980, 70);

	pauza.setFont(font);
	pauza.setFillColor(sf::Color::Green);
	pauza.setCharacterSize(20);
	pauza.setString("W celu uzyskania pomocy i zapauzowania gry wcisnij F1");
	pauza.setPosition(350, 720);

}

void gra::wyswietlgra(sf::RenderWindow& window)
{
	window.draw(tlo);
	window.draw(punkty);
	window.draw(zycia);
	window.draw(pauza);
}