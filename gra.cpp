#include "gra.h"

gra::gra(float width, float height)
{
	font.loadFromFile("arial.ttf");

	tlo.setFillColor(sf::Color::Cyan);
	tlo.setPosition(100, 100);
	tlo.setSize(sf::Vector2f(1000, 600));
	tlo.setTextureRect(sf::IntRect(100, 100, 1000, 600));

	punkty.setFont(font);
	punkty.setCharacterSize(20);
	punkty.setFillColor(sf::Color::Green);
	punkty.setPosition(980, 50);
	punktyil = 0;

	zycia.setFillColor(sf::Color::Green);
	zycia.setCharacterSize(20);
	zycia.setFont(font);
	zycia.setPosition(100, 50);
	zyciail = 3;

	teksturapilki.loadFromFile("pilka.png");
	pilka.setTexture(teksturapilki);
	pilka.setTextureRect(sf::IntRect(0, 0, 100, 100));
	pilka.setPosition(550, 600);
	pilka.scale(0.3, 0.3);

	teksturapaletki.loadFromFile("paletka.png");
	paletka.setTexture(teksturapaletki);
	paletka.setTextureRect(sf::IntRect(0, 0, 360, 210));
	paletka.setPosition(525, 650);
	paletka.scale(0.2, 0.2);

	teksturabloki.loadFromFile("bloki.png");
	for (int i = 0; i <50; i++)
	{
		blok[i].setTexture(teksturabloki);
		blok[i].setTextureRect(sf::IntRect(0, 0, 100, 100));
		blok[i].scale(0.5, 0.5);
	}

	for (int i = 0; i < 15; i++)
	{
		blok[i].setPosition(i * 60 + 150, 400);
	}
	for(int j=15;j<25;j++)
	{
		blok[j].setPosition((j-15)* 90 + 190, 300);
	}
	for (int k = 25; k < 40; k++)
	{
		blok[k].setPosition((k-25) * 60 + 150, 200);
	}
	for (int l = 40; l < 50; l++)
	{
		blok[l].setPosition((l-40) * 90 + 190, 100);
	}

	gameover0.setFont(font);
	gameover0.setFillColor(sf::Color::Magenta);
	gameover0.setCharacterSize(70);
	gameover0.setString("GAME OVER");
	gameover0.setPosition(90, 80);

	gameover1.setFont(font);
	gameover1.setFillColor(sf::Color::Green);
	gameover1.setCharacterSize(30);
	gameover1.setString("Nacisnij ESC by wrocic do menu");
	gameover1.setPosition(80, 270);

	pauza.setFont(font);
	pauza.setFillColor(sf::Color::Green);
	pauza.setCharacterSize(20);
	pauza.setString("W celu uzyskania pomocy i zapauzowania gry wcisnij F1");
	pauza.setPosition(350, 720);

	gratulacje.setFont(font);
	gratulacje.setFillColor(sf::Color::Magenta);
	gratulacje.setCharacterSize(70);
	gratulacje.setString("GRATULACJE");
	gratulacje.setPosition(70, 30);

	wygrana0.setFont(font);
	wygrana0.setFillColor(sf::Color::Green);
	wygrana0.setCharacterSize(30);
	wygrana0.setString("Udalo Ci sie wygrac");
	wygrana0.setPosition(80, 150);

	wygrana1.setFont(font);
	wygrana1.setFillColor(sf::Color::Green);
	wygrana1.setCharacterSize(30);
	wygrana1.setPosition(80, 210);

	wygrana2.setFont(font);
	wygrana2.setFillColor(sf::Color::Green);
	wygrana2.setCharacterSize(20);
	wygrana2.setString("w celu wrocenia do menu wcisnij ESC");
	wygrana2.setPosition(80, 270);
}

void gra::wyswietlwygrana(sf::RenderWindow& window)
{
	window.draw(gratulacje);
	window.draw(wygrana0);
	window.draw(wygrana1);
	window.draw(wygrana2);

}

void gra::napiszzycia()
{
	zycia.setString("Zycia : " + std::to_string(zyciail));
}

void gra::napiszpunkty()
{
	punkty.setString("Punkty : " + std::to_string(punktyil));
}

void gra::napiszpunktykoniec()
{
	wygrana1.setString("Twoj wynik to: " + std::to_string(punktyil));
}

void gra::wyswietlinterfejs(sf::RenderWindow& window)
{
	window.draw(tlo);
	window.draw(punkty);
	window.draw(zycia);
	window.draw(pauza);
	window.draw(paletka);
	window.draw(pilka);
	for (int i = 0; i < 50; i++)
		window.draw(blok[i]);
}

void gra::przegrana()
{
	xVelpilki = 0;
	yVelpilki = 0;
}

void gra::wyswietlprzegrana(sf::RenderWindow& window)
{
	window.draw(gameover0);
	window.draw(gameover1);
	window.draw(wygrana1);
}

void gra::sprawdzKolizjeScianyPilki()
{
	if (position.x <= 90 || position.x >= 1080)
		xVelpilki *= -1;

	if (position.y <= 90)
		yVelpilki *= -1;

	if (position.y >= 680 && zyciepodloga > 1)
	{
		yVelpilki *= -1;
		zyciadol();
	}

	if (position.y >= 680 && zyciail == 0)
	{
		przegrana();
	}
}

void gra::odbijblok()
{
	sf::IntRect pilkachwilowa(pilka.getPosition().x, pilka.getPosition().y, 25, 25);
	sf::IntRect blokichwilowe[50];
	for (int i = 0; i < 50; i++)
	{
		blokichwilowe[i].left = blok[i].getPosition().x;
		blokichwilowe[i].top = blok[i].getPosition().y;
		blokichwilowe[i].height = 50;
		blokichwilowe[i].width = 50;
	}
	for (int j = 0; j < 50; j++)
	{
		if (blokichwilowe[j].intersects(pilkachwilowa))
		{
			punktplus();
			blok[j].setPosition(3000, 0);

			if (pilka.getPosition().y > 90 && pilka.getPosition().y < 140)
				xVelpilki *= -1;

			else if (pilka.getPosition().y > 190 && pilka.getPosition().y < 240)
				xVelpilki *= -1;

			else if (pilka.getPosition().y > 290 && pilka.getPosition().y < 340)
				xVelpilki *= -1;

			else if (pilka.getPosition().y > 390 && pilka.getPosition().y < 440)
				xVelpilki *= -1;

			else
				yVelpilki *= -1;;
		}
	}

}

void gra::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	pilka.move(pos);
	position = pilka.getPosition();
}

void gra::animuj()
{
	sprawdzKolizjeScianyPilki();
	przesun(xVelpilki, yVelpilki);
}

void gra::ruchpaletkilewo()
{
	paletka.move(-20, 0);
}

void gra::ruchpaletkiprawo()
{
	paletka.move(20, 0);
}

void gra::odbijpaletke()
{
	sf::IntRect pilkachwilowa(pilka.getPosition().x, pilka.getPosition().y, 30, 30);
	sf::IntRect paletkachwilowa(paletka.getPosition().x, paletka.getPosition().y, 72, 40);
	if (pilkachwilowa.intersects(paletkachwilowa))
	{
		yVelpilki *= -1;
	}

}

void gra::sprawdzKolizjeScianyPaletki()
{
	position2=paletka.getPosition();
	if (position2.x <= 120)
		position2.x = 120;
	if (position2.x >= 1010)
		position2.x = 1010;
	paletka.setPosition(position2);
}



