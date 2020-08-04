#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Awesome Game");
        window.clear();
        sf :: RectangleShape rectangle[70][70];
        pair<int, int> pr = {20, 20};
        int x = 0, y = 0;
        for (int i = 0; i < 70; ++i) {
            y += 10; x = 0;
            for (int j = 0; j < 70; ++j) {
                x += 10;
                rectangle[i][j].setSize(sf::Vector2f(10, 10));
                rectangle[i][j].setOutlineColor(sf::Color::Green);
                rectangle[i][j].setOutlineThickness(2);
                rectangle[i][j].setPosition(x, y);
                if (x == pr.first and y == pr.second) rectangle[i][j].setFillColor(sf::Color::Red);
                window.draw(rectangle[i][j]);
            }
        }
         while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf :: Event :: EventType :: Closed :
                    window.close();
                    break;
                case sf :: Event :: EventType :: KeyPressed :
                        if(event.key.code == sf::Keyboard::Left){
                            pr.first -= 10;
                        }
                        else if(event.key.code== sf::Keyboard::Right){
                            pr.first += 10;
                        }
                        else if(event.key.code==sf::Keyboard::Up){
                            pr.second -= 10;
                        }
                        else if(event.key.code==sf::Keyboard::Down){
                            pr.second += 10;
                        }
                        break;
                }
            }
        window.clear();
        int x = 0, y = 0;
        for (int i = 0; i < 70; ++i) {
        y += 10; x = 0;
        for (int j = 0; j < 70; ++j) {
            x += 10;
            rectangle[i][j].setSize(sf::Vector2f(10, 10));
            rectangle[i][j].setOutlineColor(sf::Color::Green);
            rectangle[i][j].setOutlineThickness(2);
            rectangle[i][j].setPosition(x, y);
            rectangle[i][j].setFillColor(sf::Color::White);
            if (x == pr.first and y == pr.second) rectangle[i][j].setFillColor(sf::Color::Red);
            window.draw(rectangle[i][j]);
        }
        }
        window.display();
    }
    return 0;
}