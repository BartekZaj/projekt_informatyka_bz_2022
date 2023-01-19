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
#include "zapytanie.h"
#include "opcje.h"
#include "pomoc.h"
#include "gra.h"
#include "pauza.h"




int main() 
{
	setlocale(LC_CTYPE, "Polish");
a:
	sf::RenderWindow Menu(sf::VideoMode(1200, 800), "Menu");

	menu menu(1200, 800);
	zapytanie zapytanie(600, 400);
	pauza pauza(600, 400);
	opcje opcje(1200, 800);
	pomoc pomoc(1200, 800);
	gra gra(1200, 800);
	sf::Clock zegar;
	int trudnosc = 0;
	int sterowanie = 0;
	gra.zyciail = 3;
	gra.punktyil = 0;
	while (Menu.isOpen())
	{
		b:
		sf::Event event;
		while (Menu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Menu.close(); 		
				
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

							
							case 0:	
																															//OKNO GRY
							
								Menu.clear();
								while (Menu.isOpen())
								{
									sf::Event eventgra;
									while (Menu.pollEvent(eventgra))
									{
										if (eventgra.type == sf::Event::Closed)
											Menu.close();
									
									

										switch (sterowanie)
										{
										case 0:
											if (eventgra.type == sf::Event::KeyPressed && eventgra.key.code == sf::Keyboard::A)
											{
												gra.sprawdzKolizjeScianyPaletki();
												gra.ruchpaletkilewo();
											}

											if (eventgra.type == sf::Event::KeyPressed && eventgra.key.code == sf::Keyboard::D)
											{
												gra.sprawdzKolizjeScianyPaletki();
												gra.ruchpaletkiprawo();
											}
											break;
										case 1:
											if (eventgra.type == sf::Event::KeyPressed && eventgra.key.code == sf::Keyboard::Left)
											{
												gra.sprawdzKolizjeScianyPaletki();
												gra.ruchpaletkilewo();
											}

											if (eventgra.type == sf::Event::KeyPressed && eventgra.key.code == sf::Keyboard::Right)
											{
												gra.sprawdzKolizjeScianyPaletki();
												gra.ruchpaletkiprawo();
											}
											break;
										}
										
										if (eventgra.type == sf::Event::KeyPressed && eventgra.key.code == sf::Keyboard::R)
										{
											gra.pilka.setPosition(550, 600);
											gra.zyciadol();
											if (gra.zyciail == 0)
											{
												gra.xVelpilki = 0;
											}

										}

										switch (trudnosc)
										{
											
											case 0:
												if (gra.punktyil == 500 )
												{
													sf::RenderWindow Wygrana(sf::VideoMode(600, 400), "Wygrana");
													gra.wyswietlwygrana(Wygrana);
													while (Wygrana.isOpen())
													{
														sf::Event eventwygrana;
														while (Wygrana.pollEvent(eventwygrana))
														{
															if (eventwygrana.type == sf::Event::Closed)
																Wygrana.close();

															if (eventwygrana.type == sf::Event::KeyPressed && eventwygrana.key.code == sf::Keyboard::Escape)
																goto a;
														}

														Wygrana.clear();
														gra.wyswietlwygrana(Wygrana);
														gra.napiszpunktykoniec();
														Wygrana.display();
													}
												}
											break;
											case 1:
												if (gra.punktyil == 1000)
												{
													sf::RenderWindow Wygrana(sf::VideoMode(600, 400), "Wygrana");
													gra.wyswietlwygrana(Wygrana);
													while (Wygrana.isOpen())
													{
														sf::Event eventwygrana;
														while (Wygrana.pollEvent(eventwygrana))
														{
															if (eventwygrana.type == sf::Event::Closed)
																Wygrana.close();
																
															if (eventwygrana.type == sf::Event::KeyPressed && eventwygrana.key.code == sf::Keyboard::Escape)
																goto a;
														}
														Wygrana.clear();
														gra.wyswietlwygrana(Wygrana);
														gra.napiszpunktykoniec();
														Wygrana.display();
													}
												}
											break;
										}
										if (gra.xVelpilki==0)
										{
											
											sf::RenderWindow Gameover(sf::VideoMode(600, 400), "Gameover");
											gra.wyswietlprzegrana(Gameover);
											while (Gameover.isOpen())
											{
												sf::Event eventgameover;
												while (Gameover.pollEvent(eventgameover))
												{
													if (eventgameover.type == sf::Event::Closed)
														Gameover.close();

													if (eventgameover.type == sf::Event::KeyPressed && eventgameover.key.code == sf::Keyboard::Escape)
														goto a;
												}
												Gameover.clear();
												gra.wyswietlprzegrana(Gameover);
												gra.napiszpunktykoniec();
												Gameover.display();

											}
										}

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
										sf::RenderWindow Pauza(sf::VideoMode(600, 400), "Pauza");
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
									gra.napiszpunkty();
									gra.napiszzycia();
									gra.wyswietlinterfejs(Menu);
									gra.odbijblok();
									gra.odbijpaletke();
									
									
									if (zegar.getElapsedTime().asMilliseconds() > 5.0f)
									{
										gra.animuj();
										zegar.restart();
									}
								
									Menu.display();
								
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
														gra.xVelpilki = 1;
														gra.yVelpilki = 1.5;
														gra.zyciail = 3;
														gra.trudnoscpunkty = 1;
														break;

														case 1:
														opcje.trudnosc[1].setFillColor(sf::Color::Green);
														opcje.trudnosc[0].setFillColor(sf::Color::Red);
														trudnosc = 1;
														gra.xVelpilki = 1.5;
														gra.yVelpilki = 2;
														gra.zyciail = 1;
														gra.trudnoscpunkty = 2;
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
	
	}
	return 0;
}

