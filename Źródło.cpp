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
#include <locale.h>
#include "menu.h"
#include "paletka.h"
#include "zapytanie.h"
#include "opcje.h"
#include "pomoc.h"
#include "gra.h"
#include "pauza.h"

/*
typedef struct {                                                              Lista graczy
	char nazwa[20];
	int liczb_pkt;
	char data[40];
} gracz_cechy;

void players_to_file()
{
	srand(time(NULL));
	gracz_cechy playerschar[6];

	FILE* fp;
	fp = fopen("gracze.dat", "w+b");

	strcpy(playerschar[0].nazwa, "Bartek");
	strcpy(playerschar[1].nazwa, "Detek");
	strcpy(playerschar[2].nazwa, "Andrzej");
	strcpy(playerschar[3].nazwa, "Kuropatwa");
	strcpy(playerschar[4].nazwa, "Alley_Boss");
	strcpy(playerschar[5].nazwa, "Kiroto");

	time_t rawtime;

	time(&rawtime);

	for (int i = 0; i < 6; i++)
		playerschar[i].liczb_pkt = rand() % 2000;
	strcpy(playerschar[0].data, ctime(&rawtime));
	strcpy(playerschar[1].data, ctime(&rawtime));
	strcpy(playerschar[2].data, ctime(&rawtime));
	strcpy(playerschar[3].data, ctime(&rawtime));
	strcpy(playerschar[4].data, ctime(&rawtime));
	strcpy(playerschar[5].data, ctime(&rawtime));
	fwrite(playerschar, sizeof(gracz_cechy), 6, fp);
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
	sf::Text* players;
	gracz_cechy* player_char;
	sf::Font czcionka;
	int Np;
public:
	players_list(int N);
	void laduj();
	void sortuj();
	void zapisz();
	void draw(sf::RenderWindow& window);
};

players_list::players_list(int N)
{

	if (!czcionka.loadFromFile("arial.ttf"))
		return;

	FILE* fp = fopen("gracze.dat", "r+b");
	unsigned int rozmiar_plik = 0, ile_graczy = 0;
	fseek(fp, 0, SEEK_END);
	rozmiar_plik = ftell(fp);
	ile_graczy = rozmiar_plik / sizeof(gracz_cechy);
	if (N > ile_graczy)
	{
		Np = 5;
	}
	else
	{
		Np = N;
	}

	players = new sf::Text[Np];
	player_char = new gracz_cechy[Np];

	rewind(fp);
	fread(player_char, sizeof(gracz_cechy), Np, fp);
	fclose(fp);

	for (int i = 0; i < Np; i++)
	{
		players[i].setFont(czcionka);
		players[i].setCharacterSize(30);
		players[i].setFillColor(sf::Color::Red);
		players[i].setPosition(10 + 800 / 4, 20 + i * 50);

	}
}

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
}*/
class interfejs
{
public:
	interfejs(sf::Vector2f position);
	~interfejs();
	void draw(sf::RenderWindow& win);
	void setText(sf::Text* text1, sf::Text* text2, sf::Text* text3);
protected:
	sf::RectangleShape* int_1;
	sf::Font* font;
	sf::Text* text1;
	sf::Text* text2;
	sf::Text* text3;
	sf::Vector2f position;
	void init(sf::Vector2f widht_height);
};

interfejs::interfejs(sf::Vector2f position)
{
	this->position.x = position.x;
	this->position.y = position.y;
	sf::Vector2f width_height(756.f, 500);
	init(width_height);
}

interfejs::~interfejs()
{
	delete int_1;
	int_1 = NULL;
}

void interfejs::init(sf::Vector2f width_height)
{
	int_1 = new sf::RectangleShape;
	font = new sf::Font;
	text1 = new sf::Text;
	text2 = new sf::Text;
	text3 = new sf::Text;
	font->loadFromFile("arial.ttf");
	text1->setFont(*font);
	text2->setFont(*font);
	text3->setFont(*font);

	int_1->setPosition(22.f, 55.f);
	int_1->setSize(width_height);
	int_1->setFillColor(sf::Color(0, 255, 255));
	setText(text1, text2, text3);

}
void interfejs::draw(sf::RenderWindow& win)
{
	win.draw(*int_1);
	win.draw(*text1);
	win.draw(*text2);
	win.draw(*text3);

}
void interfejs::setText(sf::Text* text1, sf::Text* text2, sf::Text* text3)
{
	text1->setString("zycie");
	text2->setString("Punkty :");
	text3->setString("Kliknij r by zrestartowac");
	text1->setCharacterSize(24);
	text2->setCharacterSize(24);
	text3->setCharacterSize(24);
	text1->setFillColor(sf::Color(135, 206, 255));
	text2->setFillColor(sf::Color(240, 248, 255));
	text3->setFillColor(sf::Color(234, 221, 202));
	text1->setPosition(50.f, 10.f);
	text2->setPosition(650.f, 10.f);
	text3->setPosition(280.f, 560.f);
}



class Pilka                                                           /*Pi³ka odbijaj¹ca siê*/
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



/*                                                      pod³oga
class podloga
{
private:
	sf::Vector2f position;
	float xVel = 1, yVel = 1.7;
	sf::Texture tekstura;
	sf::Sprite pSprite;

public:
	podloga(float x_in, float y_in)
	{
		position.x = x_in;
		position.y = y_in;

	}
};
*/


/*																							pilka
int main()
{

	sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML animation");
	sf::View view = window.getDefaultView();
	sf::Vector2f rozmiarI((window.getSize().x - 50), (window.getSize().y - 50));
	interfejs inter(rozmiarI);
	sf::Texture tekstura;
	tekstura.loadFromFile("pilka.png");
	sf::Sprite pokeball(tekstura);
	Pilka pb(40, 10, 1000, 1000);
	sf::Clock zegar;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::Resized)
			{
				view.setSize({
					static_cast<float>(event.size.width),
					static_cast<float>(event.size.height)
					});

				window.setView(view);
			}
		}
		window.clear();
		inter.drawObiekty(window);
	}
		window.clear(sf::Color::Green);
		window.draw(pb.getPilka());
		window.display();
		if (zegar.getElapsedTime().asMilliseconds() > 5.0f)
		{
			pb.animuj();
			zegar.restart();
		}

	}

	//players_to_file();                                                          Lista graczy

	/*players_list* pl = new players_list(8);
	pl->sortuj();
	pl->laduj();

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		pl->draw(window);

		window.display();
	}*/

int main() 
{
	setlocale(LC_CTYPE, "Polish");
a:
	sf::RenderWindow Menu(sf::VideoMode(1200, 800), "Menu");

	//sf::View view = window.getDefaultView();
	//sf::Vector2f rozmiarI((window.getSize().x - 100), (window.getSize().y - 50));
	menu menu(1200, 800);
	zapytanie zapytanie(600, 400);
	pauza pauza(600, 400);
	opcje opcje(1200, 800);
	pomoc pomoc(1200, 800);
	gra gra(1200, 800);
	//interfejs one(sf::Vector2f(800.f, 600.f));
	//interfejs inter(rozmiarI);
	sf::Texture tekstura;
	tekstura.loadFromFile("pilka.png");
	sf::Sprite pokeball(tekstura);
	Pilka pb(40, 10, 800, 800);
	sf::Clock zegar;
	int trudnosc = 0;
	int sterowanie = 0;

	while (Menu.isOpen())
	{
		b:
		sf::Event event;
		while (Menu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Menu.close();
		
			/*if (event.type == sf::Event::Resized)
			{
				view.setSize(
					{
					static_cast<float>(event.size.width),
					static_cast<float>(event.size.height)
					});

				window.setView(view);
			}*/ 		
				
			switch (event.type)
			{	
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
						case sf::Keyboard::Up:
							menu.wyzej();
							break;
						case sf::Keyboard::Down:
							menu.nizej();
							break;
						case sf::Keyboard::Return:
			
						switch (menu.klik())
						{
							case 0:																													//OKNO GRY
								Menu.clear();
								while (Menu.isOpen())
								{
									sf::Event eventgra;
									while (Menu.pollEvent(eventgra))
									{
										if (eventgra.type == sf::Event::Closed)
											Menu.close();

										if (eventgra.type == sf::Event::KeyPressed && eventgra.key.code==sf::Keyboard::Escape)
										{
											sf::RenderWindow Zapytanie(sf::VideoMode(600, 400), "Zapytanie");
											zapytanie.wyswietlzap(Zapytanie);
												while (Zapytanie.isOpen())
												{
													sf::Event eventzap;
													while (Zapytanie.pollEvent(eventzap))
													{
														if (eventzap.type == sf::Event::Closed)
															Zapytanie.close();

														switch (eventzap.type)
														{
															case sf::Event::KeyReleased:
																switch (eventzap.key.code)
																{
																	case sf::Keyboard::Left:
																		zapytanie.lewozap();
																		break;
																	case sf::Keyboard::Right:
																		zapytanie.prawozap();
																		break;
																	case sf::Keyboard::Return:
																		
																		switch (zapytanie.klikzap())
																		{
																		case 0:
																			Zapytanie.close();
																			Menu.close();
																			goto a;
																			break;
																		case 1:
																			Zapytanie.close();
																			zapytanie.lewozap();
																			break;
																		}
																	
																}
														}

													}
													Zapytanie.clear();
													zapytanie.wyswietlzap(Zapytanie);
													Zapytanie.display();

												}
											

										}

									}

									if (eventgra.type == sf::Event::KeyPressed && eventgra.key.code == sf::Keyboard::F1)
									{
										sf::RenderWindow Pauza(sf::VideoMode(600, 400), "Zapytanie");
										pauza.wyswietlpauza(Pauza);
										while (Pauza.isOpen())
										{
											sf::Event eventpauza;
											while (Pauza.pollEvent(eventpauza))
											{
												if (eventpauza.type == sf::Event::Closed)
													Pauza.close();

												switch (eventpauza.type)
												{
												case sf::Event::KeyReleased:
													switch (eventpauza.key.code)
													{
													case sf::Keyboard::Escape:
														Pauza.close();
														break;
													}
												}
											}
											Pauza.clear();
											pauza.wyswietlpauza(Pauza);
											Pauza.display();
										}
									}

									Menu.clear();
									gra.wyswietlgra(Menu);
									Menu.display();
									/*
									Gra.clear();
									one.draw(window);
									window.draw(pb.getPilka());
									window.display();
									if (zegar.getElapsedTime().asMilliseconds() > 5.0f)
									{
										pb.animuj();
										zegar.restart();
									}*/
								}
								break;
							case 1:																												//WYNIKI
								Menu.clear();

								break;

							case 2:																													//OPCJE
								
								Menu.clear();
								while (Menu.isOpen())
								{
									sf::Event eventopcje;
									while (Menu.pollEvent(eventopcje))
									{
										if (eventopcje.type == sf::Event::Closed)
											Menu.close();

										if (eventopcje.type == sf::Event::KeyPressed && eventopcje.key.code == sf::Keyboard::Escape)
										{		
											Menu.clear();
											Menu.display();
											goto b;
										}

										switch (eventopcje.type)
										{
										case sf::Event::KeyReleased:
											switch (eventopcje.key.code)
											{
											case sf::Keyboard::Up:
												opcje.goraop();
												break;
											case sf::Keyboard::Down:
												opcje.dolop();
												break;
											case sf::Keyboard::Left:
												opcje.lewoop();
												break;
											case sf::Keyboard::Right:
												opcje.prawoop();
												break;
											case sf::Keyboard::Return:
												switch (opcje.wiersz)														//    WYBOR OPCJE TRUDNOSC/TLO/STEROWANIE
												{
												case 0:
													opcje.kliktr();
													switch (opcje.wybortr)
													{
														case 0:
														opcje.trudnosc[0].setFillColor(sf::Color::Green);
														opcje.trudnosc[1].setFillColor(sf::Color::Red);
														trudnosc = 0;
														break;

														case 1:
														opcje.trudnosc[1].setFillColor(sf::Color::Green);
														opcje.trudnosc[0].setFillColor(sf::Color::Red);
														trudnosc = 1;
														break;
													}
													break;
												case 1:
													switch (opcje.wybortla)
													{
														case 0:
															opcje.rodzajtla[0].setFillColor(sf::Color::Green);
															opcje.rodzajtla[1].setFillColor(sf::Color::Red);
															opcje.rodzajtla[2].setFillColor(sf::Color::Red);  
															gra.tlo.setFillColor(sf::Color::Cyan);
															break;
														case 1:
															opcje.rodzajtla[0].setFillColor(sf::Color::Red);
															opcje.rodzajtla[1].setFillColor(sf::Color::Green);
															opcje.rodzajtla[2].setFillColor(sf::Color::Red);
															gra.tlo.setFillColor(sf::Color(245, 122, 13));
															break;
														case 2:
															opcje.rodzajtla[0].setFillColor(sf::Color::Red);
															opcje.rodzajtla[1].setFillColor(sf::Color::Red);
															opcje.rodzajtla[2].setFillColor(sf::Color::Green);
															gra.tlo.setFillColor(sf::Color(247,53,188));
															break;
													}
													break;
												case 2:
													switch (opcje.wyborster)
													{
														case 0:
															opcje.sterowanie[0].setFillColor(sf::Color::Green);
															opcje.sterowanie[1].setFillColor(sf::Color::Red);
															sterowanie = 0;//sterowanie A i D
															break;
														case 1:
															opcje.sterowanie[0].setFillColor(sf::Color::Red);
															opcje.sterowanie[1].setFillColor(sf::Color::Green);
															sterowanie = 1;//sterowanie strzalkami
															break;
													}
													break;
												}
												
											}
										}

									}
									Menu.clear();
									opcje.wyswietlopcje(Menu);
									Menu.display();
								
								}
							case 3:																													//POMOC
								Menu.clear();
								while (Menu.isOpen())
								{
									sf::Event eventpomoc;
									while (Menu.pollEvent(eventpomoc))
									{
										if (eventpomoc.type == sf::Event::Closed)
											Menu.close();

										if (eventpomoc.type == sf::Event::KeyPressed && eventpomoc.key.code == sf::Keyboard::Escape)
										{
											Menu.clear();
											Menu.display();
											goto b;
										}
									}
									Menu.clear();
									pomoc.wyswietlpomoc(Menu);
									Menu.display();
								}
								break;

	
							case 4:																													//WYJSCIE
								Menu.close();
								break;

						}						
					}
			}
		}
		Menu.clear();
		menu.wyswietlmenu(Menu);
		Menu.display();
		/*
		window.clear();
		one.draw(window);
		window.draw(pb.getPilka());
		window.display();
		if (zegar.getElapsedTime().asMilliseconds() > 5.0f)
		{
			pb.animuj();
			zegar.restart();
		}
		*/

		/*window.display();*/
	}
	return 0;
}

