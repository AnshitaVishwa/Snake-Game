#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Awesome Game");
        sf :: RectangleShape rectangle[70][70];
        pair<int, int> food = {60, 60}, pr;
        deque<pair<int, int>> snake;
        snake.push_front({30, 30});
        snake.push_front({40, 30});
        snake.push_front({50, 30});
        sf::Font font;
        if (!font.loadFromFile("game_over.ttf"))
        {
            cout << "Error";
        }
        sf::Text text;
        text.setFont(font);
        text.setString("Game Over");
        text.setCharacterSize(150);
        text.setFillColor(sf::Color::Blue);
        bool gameOver = false;
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
                            pr = snake.front();
                            pr.first -= 10;
                            for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                                if (*itr == pr) {
                                    gameOver = true;
                                }
                            }
                            snake.pop_back();
                            snake.push_front(pr);
                            if (pr == food) {
                                snake.push_back(food);
                                int fx, fy;
                                while (1) {
                                    fx = 200 + (rand() % (600 - 200 + 1));
                                    fy = 200 + (rand() % (600 - 200 + 1));
                                    if (fx % 10 == 0 and fy % 10 == 0) break;
                                }
                                food = {fx, fy};
                            }
                        }
                        else if(event.key.code== sf::Keyboard::Right){
                            pr = snake.front();
                            pr.first += 10;
                            for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                                if (*itr == pr) {
                                    gameOver = true;
                                }
                            }
                            snake.pop_back();
                            snake.push_front(pr);
                            if (pr == food) {
                                snake.push_back(food);
                                int fx, fy;
                                while (1) {
                                    fx = 200 + (rand() % (600 - 200 + 1));
                                    fy = 200 + (rand() % (600 - 200 + 1));
                                    if (fx % 10 == 0 and fy % 10 == 0) break;
                                }
                                food = {fx, fy};
                            }
                        }
                        else if(event.key.code==sf::Keyboard::Up){
                            pr = snake.front();
                            pr.second -= 10;
                            for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                                if (*itr == pr) {
                                    gameOver = true;
                                }
                            }
                            snake.pop_back();
                            snake.push_front(pr);
                           if (pr == food) {
                                snake.push_back(food);
                                int fx, fy;
                                while (1) {
                                    fx = 200 + (rand() % (600 - 200 + 1));
                                    fy = 200 + (rand() % (600 - 200 + 1));
                                    if (fx % 10 == 0 and fy % 10 == 0) break;
                                }
                                food = {fx, fy};
                            }
                        }
                        else if(event.key.code==sf::Keyboard::Down){
                            pr = snake.front();
                            pr.second += 10;
                            for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                                if (*itr == pr) {
                                    gameOver = true;
                                }
                            }
                            snake.pop_back();
                            snake.push_front(pr);
                           if (pr == food) {
                                snake.push_back(food);
                                int fx, fy;
                                while (1) {
                                    fx = 200 + (rand() % (600 - 200 + 1));
                                    fy = 200 + (rand() % (600 - 200 + 1));
                                    if (fx % 10 == 0 and fy % 10 == 0) break;
                                }
                                food = {fx, fy};
                            }
                        }
                        break;
                }
            }
        window.clear();
        if (gameOver) {
            window.draw(text);
        } else {
            int x = 0, y = 0;
            pair<int, int> head = snake.front();
            for (int i = 0; i < 70; ++i) {
                y += 10; x = 0;
                for (int j = 0; j < 70; ++j) {
                    x += 10;
                    rectangle[i][j].setSize(sf::Vector2f(10, 10));
                    rectangle[i][j].setOutlineColor(sf::Color::Green);
                    rectangle[i][j].setOutlineThickness(2);
                    rectangle[i][j].setPosition(x, y);
                    rectangle[i][j].setFillColor(sf::Color::White);
                    if (x == food.first and y == food.second) rectangle[i][j].setFillColor(sf::Color::Black);
                    for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                        pair<int, int> t = *itr;
                        if (t.first == x and t.second == y) rectangle[i][j].setFillColor(sf::Color::Red);
                    }
                    window.draw(rectangle[i][j]);
                }
            }
        }
        window.display();
    }
    return 0;
}