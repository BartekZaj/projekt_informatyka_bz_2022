#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//Pi³ka odbijaj¹ca siê od ruchomego pod³o¿a przesuwanego przez u¿ytkownika. Pi³ka trafia w obiekty umieszczone w okreœlonym miejscu scenerii.
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <string>
#include <ctime>
#include <cstdlib>

typedef struct {
	char nazwa[20];
	int liczb_pkt;
	char data[40];
} gracz_cechy;

void players_to_file()
{
	srand(time(NULL));
	gracz_cechy playerschar[10];

	FILE* fp;
	fp = fopen("gracze.dat", "w+b");

	strcpy(playerschar[0].nazwa, "Johny");
	strcpy(playerschar[1].nazwa, "Bathman");
	strcpy(playerschar[2].nazwa, "Dedman");
	strcpy(playerschar[3].nazwa, "Bethymanamm");
	strcpy(playerschar[4].nazwa, "Alloy_jr");
	strcpy(playerschar[5].nazwa, "Poul");
	strcpy(playerschar[6].nazwa, "Snake");
	strcpy(playerschar[7].nazwa, "BK");
	strcpy(playerschar[8].nazwa, "Pascal");
	strcpy(playerschar[9].nazwa, "Java");

	time_t rawtime;

	time(&rawtime);

	for (int i = 0; i < 10; i++)
		playerschar[i].liczb_pkt = rand() % 2000;
	strcpy(playerschar[0].data, ctime(&rawtime));
	strcpy(playerschar[1].data, ctime(&rawtime));
	strcpy(playerschar[2].data, ctime(&rawtime));
	strcpy(playerschar[3].data, ctime(&rawtime));
	strcpy(playerschar[4].data, ctime(&rawtime));
	strcpy(playerschar[5].data, ctime(&rawtime));
	strcpy(playerschar[6].data, ctime(&rawtime));
	strcpy(playerschar[7].data, ctime(&rawtime));
	strcpy(playerschar[8].data, ctime(&rawtime));
	strcpy(playerschar[9].data, ctime(&rawtime));
	fwrite(playerschar, sizeof(gracz_cechy), 10, fp);
	fclose(fp);
}

int porownaj(const void* left, const void* right) {
	const gracz_cechy* a = (const gracz_cechy*)left;
	const gracz_cechy* b = (const gracz_cechy*)right;
	if (a->liczb_pkt > b->liczb_pkt) {
		return -1;
	}
	else if (a->liczb_pkt < b->liczb_pkt) {
		return 1;
	}
	else {
		return 0;
	}
}

class players_list {
private:
	sf::Text* players;//dane tekstowe do wyswietlenia
	gracz_cechy* player_char;//rzeczywista specyfikacja graczy
	sf::Font czcionka;
	int Np;
public:
	players_list(int N);
	void laduj();
	void sortuj();
	void zapisz();
	void draw(sf::RenderWindow& window);
};


void players_list::laduj()
{
	std::string tmp_tekst;
	for (int i = 0; i < Np; i++)
	{
		players[i].setFont(czcionka);
		players[i].setCharacterSize(30);
		players[i].setFillColor(sf::Color::Red);
		players[i].setPosition(10 + 800 / 4, 20 + i * 50);

		tmp_tekst.assign(player_char[i].nazwa);
		tmp_tekst += " Punkty: " + std::to_string(player_char[i].liczb_pkt);
		tmp_tekst += "        ";
		tmp_tekst += "Data: ";
		tmp_tekst += (player_char[i].data);
		players[i].setString(tmp_tekst);
	}
}


void players_list::sortuj()
{
	qsort(player_char, Np, sizeof(gracz_cechy), porownaj);
}

void players_list::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Np; i++)
	{
		window.draw(players[i]);
	}
}
/*class Pilka
{
private:
	sf::Vector2f position;
	float xVel = 1, yVel = 1.7;
	sf::Texture tekstura;
	sf::Sprite pSprite;
	sf::Vector2f rozmiar_okna;
public:
	Pilka(float x_in, float y_in, float o, float i)
	{
		position.x = x_in;
		position.y = y_in;
		rozmiar_okna.x = o;
		rozmiar_okna.y = i;
		tekstura.loadFromFile("pilka.png");
		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);
	}
	void przesun(float x_in, float y_in);
	sf::Sprite getPilka()
	{
		return pSprite;
	}
	void sprawdzKolizjeSciany();
	void animuj();
};
void Pilka::przesun(float x_in, float y_in)
{
	sf::Vector2f pos;
	pos.x = x_in;
	pos.y = y_in;
	pSprite.move(pos);
	position = pSprite.getPosition();
}

void Pilka::sprawdzKolizjeSciany()
{
	if (position.x <= 0 || position.x >= rozmiar_okna.x - 100)
		xVel *= -1;

	if (position.y <= 0 || position.y >= rozmiar_okna.y - 100)
		yVel *= -1;

}

void Pilka::animuj()
{
	sprawdzKolizjeSciany();
	przesun(xVel, yVel);
}

*/
int main()
{

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML animation");
	/*sf::Event event;

	sf::Texture tekstura;
	tekstura.loadFromFile("pilka.png");
	sf::Sprite pokeball(tekstura);
	Pilka pb(40, 10, 1000, 1000);
	sf::Clock zegar;

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Green);
		window.draw(pb.getPilka());
		window.display();
		if (zegar.getElapsedTime().asMilliseconds() > 5.0f) {
			pb.animuj();
			zegar.restart();
		}
	}
	*/
	players_to_file();//potrzebne tylko raz!

	players_list* pl = new players_list(8);
	pl->sortuj();
	pl->laduj();
	// petla wieczna - dopoki okno jest otwarte
	while (window.isOpen())
	{
		// w kazdej iteracji petli sprawdzaj zdarzenia
		sf::Event event;
		while (window.pollEvent(event))
		{
			// jezeli odebrano zdarzenie "Closed" zamknij okno
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		pl->draw(window);

		window.display();
	}
	return 0;
}