#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Network.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include "player.h"
#include "Collider.h"
#include <string>

int main() {

    sf::RenderWindow window(sf::VideoMode(1366, 768), "Newton", sf::Style::Close | sf::Style::Titlebar);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        throw("couldnt load the font");
    sf::Texture cialotexture;
    cialotexture.loadFromFile("ball.png");

    //stworzenie napisów
    sf::Text tytul;
    sf::Text opcja1;
    sf::Text opcja2;
    sf::Text opcja3;
    sf::Text opcja4;
    sf::Text napis1;
    sf::Text napis2;
    sf::Text napis3;
    sf::Text velocitytext;
    sf::Text forcetext;
    sf::Text accelerationtext;

    tytul.setFont(font);
    opcja1.setFont(font);
    opcja2.setFont(font);
    opcja3.setFont(font);
    opcja4.setFont(font);
    napis1.setFont(font);
    napis2.setFont(font);
    napis3.setFont(font);
    velocitytext.setFont(font);
    forcetext.setFont(font);
    accelerationtext.setFont(font);

    //Nadanie napisom tekstu
    tytul.setString("III Zasady Dynamiki Newtona");
    opcja1.setString("I Zasada");
    opcja2.setString("II Zasada");
    opcja3.setString("III Zasada");
    opcja4.setString("Wyjdz");
    napis1.setString("I Zasada Dynamiki Newtona");
    napis2.setString("II Zasada Dynamiki Newtona");
    napis3.setString("III Zasada Dynamiki Newtona");

    tytul.setCharacterSize(70);
    opcja1.setCharacterSize(70);
    opcja2.setCharacterSize(70);
    opcja3.setCharacterSize(70);
    opcja4.setCharacterSize(70);
    napis1.setCharacterSize(70);
    napis2.setCharacterSize(70);
    napis3.setCharacterSize(70);

    //Nadanie napisom koloru
    tytul.setFillColor(sf::Color::White);
    opcja1.setFillColor(sf::Color::White);
    opcja2.setFillColor(sf::Color::White);
    opcja3.setFillColor(sf::Color::White);
    opcja4.setFillColor(sf::Color::White);
    napis1.setFillColor(sf::Color::White);
    napis2.setFillColor(sf::Color::White);
    napis3.setFillColor(sf::Color::White);
    velocitytext.setFillColor(sf::Color::White);
    forcetext.setFillColor(sf::Color::White);
    accelerationtext.setFillColor(sf::Color::White);

    //Ustawianie napisów
    tytul.setPosition(sf::Vector2f(220.0, 50.0));
    opcja1.setPosition(sf::Vector2f(600.0, 200.0));
    opcja2.setPosition(sf::Vector2f(590.0, 350.0));
    opcja3.setPosition(sf::Vector2f(580.0, 500.0));
    opcja4.setPosition(sf::Vector2f(650.0, 650.0));
    napis1.setPosition(sf::Vector2f(600.0, 0.0));
    napis2.setPosition(sf::Vector2f(600.0, 0.0));
    napis3.setPosition(sf::Vector2f(600.0, 0.0));
    velocitytext.setPosition(sf::Vector2f(10.0, 100.0));
    forcetext.setPosition(sf::Vector2f(10.0, 150.0));
    accelerationtext.setPosition(sf::Vector2f(10.0, 200.0));
    Cialo cialo(&cialotexture, 50.0f, 0.0f);

    //zmienne
    int GroundHeight = 400;
    int opcja = 1;
    bool in_menu = true;
    bool good = true;
    float force = 0.0;
    int mass = 100;
    int acceleration = 0;
    sf::Vector2f velocity1(sf::Vector2f(0, 0));

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen()) {

        deltaTime = clock.restart().asSeconds();
        sf::Event evnt;

        while (window.pollEvent(evnt)) {

            if (evnt.type == evnt.Closed) {
                window.close();
            }

            if (evnt.type == evnt.KeyPressed) {
                if (good) {
                    if (evnt.key.code == sf::Keyboard::Down) {
                        if (opcja < 4) {
                            opcja += 1;
                        }
                    }
                    if (evnt.key.code == sf::Keyboard::Up) {
                        if (opcja > 1) {
                            opcja -= 1;
                        }
                    }
                    if (evnt.key.code == sf::Keyboard::Enter or evnt.key.code == sf::Keyboard::Space) {
                        in_menu = false;
                        if (opcja != 4) {
                            std::cout << "Wybrano opcje " << opcja << std::endl;
                        }
                    }
                    good = false;
                }
                if (!in_menu) {
                    if (evnt.key.code == sf::Keyboard::A) {
                        if (force > -20.0) {
                            force -= 0.01;
                        }
                    }
                    if (evnt.key.code == sf::Keyboard::D) {
                        if (force < 20.0) {
                            force += 0.01;
                        }
                    }
                }
                if (evnt.key.code == sf::Keyboard::Escape) {
                    if (in_menu) {
                        opcja = 4;
                        in_menu = false;
                    }
                    else if (!in_menu) {
                        opcja = 1;
                        in_menu = true;
                    }

                }
            }
            if (evnt.type == evnt.KeyReleased) {
                good = true;
            }
        }
        if (in_menu) {
            if (opcja == 1)
            {
                opcja1.setFillColor(sf::Color::Red);
                opcja2.setFillColor(sf::Color::White);
                opcja3.setFillColor(sf::Color::White);
                opcja4.setFillColor(sf::Color::White);
                //cialo.update1(deltaTime);
            }

            if (opcja == 2) {
                opcja1.setFillColor(sf::Color::White);
                opcja2.setFillColor(sf::Color::Red);
                opcja3.setFillColor(sf::Color::White);
                opcja4.setFillColor(sf::Color::White);
                //cialo.update2(deltaTime);
            }
            if (opcja == 3) {
                opcja1.setFillColor(sf::Color::White);
                opcja2.setFillColor(sf::Color::White);
                opcja3.setFillColor(sf::Color::Red);
                opcja4.setFillColor(sf::Color::White);
                //cialo.update3(deltaTime);
            }
            if (opcja == 4) {
                opcja1.setFillColor(sf::Color::White);
                opcja2.setFillColor(sf::Color::White);
                opcja3.setFillColor(sf::Color::White);
                opcja4.setFillColor(sf::Color::Red);
            }

            window.draw(tytul);
            window.draw(opcja1);
            window.draw(opcja2);
            window.draw(opcja3);
            window.draw(opcja4);
        }
        else {
            if (opcja == 1) {
                velocity1.y += 981.0f * deltaTime;
                cialo.update1(deltaTime);
                cialo.Draw(window);
               // acceleration = force / mass;
                if (cialo.body.getPosition().y + cialo.body.getSize().y <= GroundHeight)
                {
                    velocity1.y += 981.0f * deltaTime;
                }
                else
                {
                    cialo.body.setPosition(cialo.body.getPosition().x, GroundHeight - cialo.body.getSize().y);
                    velocity1.y = 0;
                }

                cialo.body.move(velocity1 * deltaTime);
                
                //cialo.velocity.x += acceleration * deltaTime;
                //velocity = sqrt((predkosc.x * predkosc.x) + (predkosc.y * predkosc.y));
                window.draw(napis1);
            }
            if (opcja == 2) {
                if (force != 0) {
                    acceleration = force / mass;
                }
               // if (cialo.GetVelocity() > 0) {
                 //   acceleration -= 0.005 / mass;
               // }
                //else if (cialo.GetVelocity() < 0) {
                 //   acceleration += 0.005 / mass;
               // }
                //cialo.velocity.x += acceleration * deltaTime;
                //velocity = sqrt((predkosc.x * predkosc.x) + (predkosc.y * predkosc.y));
                window.draw(napis2);
            }
            if (opcja == 3) {
               // velocity = sqrt((dane.x * dane.x) + (dane.y * dane.y));
                window.draw(napis3);
            }
            if (opcja == 4) {
                std::cout << std::endl << std::endl << std::endl << "Aplikacja stworzona przez Dominike Lindenau oraz Dawida Gospodarek" << std::endl << std::endl << std::endl;
                window.close();
            }
           // velocitytext.setString("Predkosc ciala: " + std::to_string(velocity1));
            forcetext.setString("Sila dzialajaca na cialo: " + std::to_string(force));
            accelerationtext.setString("Przyspiesznie ciala: " + std::to_string(acceleration));
        }

        window.display();
        window.clear(sf::Color::Black);
    }
}