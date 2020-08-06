#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

int main () {
    // Window Open
    sf::RenderWindow window(sf::VideoMode(640, 640), "Awesome Game");
    // Coordinates of Food for the snake
    pair<pair<int, int>, string> food = {{192, 192}, "F"}, head;
    pair<int, int> newHead;
    // Load the image
    sf::Texture texture;
    texture.loadFromFile("image.jpg");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    // Coordinates for the head, body and Tail of the snake
    deque<pair<pair<int, int>, string>> snake;
    snake.push_front({{192, 64}, "TR"}), snake.push_front({{128, 64}, "BH"}), snake.push_front({{64, 64}, "CTL"}), snake.push_front({{64, 128}, "HD"});
    // Game Over Part
    sf::Font font;
    font.loadFromFile("game_over.ttf");
    sf::Text text;
    text.setFont(font);
    bool gameOver = false;
    int score = 0;
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
                            head = snake.front();
                            newHead = head.first;
                            newHead.first -= 64;
                            // Game over logic
                            for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                                if ((*itr).first == newHead) {
                                    gameOver = true;
                                }
                            }
                            int varX = newHead.first, varY = newHead.second;
                            if (varX < 0 or varX > 576 or varY < 0 or varY > 576) {
                                gameOver = true;
                            }
                            // Working on Tail
                            if (newHead == food.first) {
                                ++score;
                                int fx, fy;
                                while (1) {
                                    fx = (rand() % (576 - 0 + 1));
                                    fy = (rand() % (576 - 0 + 1));
                                    if (fx % 64 == 0 and fy % 64 == 0) break;
                                }
                                food = {{fx, fy}, "F"};
                            } else {
                                pair<pair<int, int>, string> tail = snake.back(), forwardTail;
                                snake.pop_back();
                                forwardTail = snake.back();
                                if (tail.second == "TD") {
                                    if (forwardTail.second == "BV") {
                                        snake.back().second = "TD";
                                    } else if (forwardTail.second == "CTR") {
                                        snake.back().second = "TR";
                                    } else if (forwardTail.second == "CTL") {
                                        snake.back().second = "TL";
                                    }
                                } else if (tail.second == "TU") {
                                    if (forwardTail.second == "BV") {
                                        snake.back().second = "TU";
                                    } else if (forwardTail.second == "CBR") {
                                        snake.back().second = "TR";
                                    } else if (forwardTail.second == "CBL") {
                                        snake.back().second = "TL";
                                    }
                                } else if (tail.second == "TR") {
                                    if (forwardTail.second == "BH") {
                                        snake.back().second = "TR";
                                    } else if (forwardTail.second == "CBL") {
                                        snake.back().second = "TD";
                                    } else if (forwardTail.second == "CTL") {
                                        snake.back().second = "TU";
                                    }
                                } else if (tail.second == "TL") {
                                    if (forwardTail.second == "BH") {
                                        snake.back().second = "TL";
                                    } else if (forwardTail.second == "CTR") {
                                        snake.back().second = "TU";
                                    } else if (forwardTail.second == "CBR") {
                                        snake.back().second = "TD";
                                    }
                                }
                            }
                            // Working on Head
                            if (head.second == "HD") {
                                snake.front().second = "CBR";
                            } else if (head.second == "HU") {
                                snake.front().second = "CTR"; 
                            } else if (head.second == "HL") {
                                snake.front().second = "BH";
                            }
                            snake.push_front({newHead, "HL"});
                        }
                        else if(event.key.code== sf::Keyboard::Right){
                            head = snake.front();
                            newHead = head.first;
                            newHead.first += 64;
                            // Game over logic
                            for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                                if ((*itr).first == newHead) {
                                    gameOver = true;
                                }
                            }
                            int varX = newHead.first, varY = newHead.second;
                            if (varX < 0 or varX > 576 or varY < 0 or varY > 576) {
                                gameOver = true;
                            }
                            // Working on Tail
                            if (newHead == food.first) {
                                ++score;
                                int fx, fy;
                                while (1) {
                                    fx = (rand() % (576 - 0 + 1));
                                    fy = (rand() % (576 - 0 + 1));
                                    if (fx % 64 == 0 and fy % 64 == 0) break;
                                }
                                food = {{fx, fy}, "F"};
                            } else {
                                 pair<pair<int, int>, string> tail = snake.back(), forwardTail;
                                snake.pop_back();
                                forwardTail = snake.back();
                                if (tail.second == "TD") {
                                    if (forwardTail.second == "BV") {
                                        snake.back().second = "TD";
                                    } else if (forwardTail.second == "CTL") {
                                        snake.back().second = "TL";
                                    } else if (forwardTail.second == "CTR") {
                                        snake.back().second = "TR";
                                    }
                                } else if (tail.second == "TU") {
                                    if (forwardTail.second == "BV") {
                                        snake.back().second = "TU";
                                    } else if (forwardTail.second == "CBL") {
                                        snake.back().second = "TL";
                                    } else if (forwardTail.second == "CBR") {
                                        snake.back().second = "TR";
                                    }
                                } else if (tail.second == "TL") {
                                    if (forwardTail.second == "BH") {
                                        snake.back().second = "TL";
                                    } else if (forwardTail.second == "CTR") {
                                        snake.back().second = "TU";
                                    } else if (forwardTail.second == "CBR") {
                                        snake.back().second = "TD";
                                    } 
                                } else if (tail.second == "TR") {
                                    if (forwardTail.second == "BH") {
                                        snake.back().second = "TR";
                                    } else if (forwardTail.second == "CTL") {
                                        snake.back().second = "TU";
                                    } else if (forwardTail.second == "CBL") {
                                        snake.back().second = "TD";
                                    }
                                }
                            }
                            // Working on Head
                            if (head.second == "HD") {
                                snake.front().second = "CBL";
                            } else if (head.second == "HU") {
                                snake.front().second = "CTL"; 
                            } else if (head.second == "HR") {
                                snake.front().second = "BH";
                            }
                            snake.push_front({newHead, "HR"});
                        }
                        else if(event.key.code==sf::Keyboard::Up){
                            head = snake.front();
                            newHead = head.first;
                            newHead.second -= 64;
                            // Game over logic
                            for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                                if ((*itr).first == newHead) {
                                    gameOver = true;
                                }
                            }
                            int varX = newHead.first, varY = newHead.second;
                            if (varX < 0 or varX > 576 or varY < 0 or varY > 576) {
                                gameOver = true;
                            }
                            // Working on Tail
                            if (newHead == food.first) {
                                ++score;
                                int fx, fy;
                                while (1) {
                                    fx = (rand() % (576 - 0 + 1));
                                    fy = (rand() % (576 - 0 + 1));
                                    if (fx % 64 == 0 and fy % 64 == 0) break;
                                }
                                food = {{fx, fy}, "F"};
                            } else {
                                pair<pair<int, int>, string> tail = snake.back(), forwardTail;
                                snake.pop_back();
                                forwardTail = snake.back();
                                if (tail.second == "TL") {
                                    if (forwardTail.second == "BH") {
                                        snake.back().second = "TL";
                                    } else if (forwardTail.second == "CBR") {
                                        snake.back().second = "TD";
                                    }  else if (forwardTail.second == "CTR") {
                                        snake.back().second = "TU";
                                    }
                                } else if (tail.second == "TR") {
                                    if (forwardTail.second == "BH") {
                                        snake.back().second = "TR";
                                    } else if (forwardTail.second == "CBL") {
                                        snake.back().second = "TD";
                                    } else if (forwardTail.second == "CTL") {
                                        snake.back().second = "TU";
                                    }
                                } else if (tail.second == "TD") {
                                    if (forwardTail.second == "BV") {
                                        snake.back().second = "TD";
                                    } else if (forwardTail.second == "CTR") {
                                        snake.back().second = "TR";
                                    } else if (forwardTail.second == "CTL") {
                                        snake.back().second = "TL";
                                    }
                                } else if (tail.second == "TU") {
                                    if (forwardTail.second == "BV") {
                                        snake.back().second = "TU";
                                    } else if (forwardTail.second == "CBR") {
                                        snake.back().second = "TR";
                                    } else if (forwardTail.second == "CBL") {
                                        snake.back().second = "TL";
                                    }
                                }
                            }
                            // Working on Head
                            if (head.second == "HL") {
                                snake.front().second = "CBL";
                            } else if (head.second == "HR") {
                                snake.front().second = "CBR"; 
                            } else if (head.second == "HU") {
                                snake.front().second = "BV";
                            }
                            snake.push_front({newHead, "HU"});
                        }
                        else if(event.key.code==sf::Keyboard::Down){
                            head = snake.front();
                            newHead = head.first;
                            newHead.second += 64;
                            // Game over logic
                            for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                                if ((*itr).first == newHead) {
                                    gameOver = true;
                                }
                            }
                            int varX = newHead.first, varY = newHead.second;
                            if (varX < 0 or varX > 576 or varY < 0 or varY > 576) {
                                gameOver = true;
                            }
                            // Working on Tail
                            if (newHead == food.first) {
                                ++score;
                                int fx, fy;
                                while (1) {
                                    fx = (rand() % (576 - 0 + 1));
                                    fy = (rand() % (576 - 0 + 1));
                                    if (fx % 64 == 0 and fy % 64 == 0) break;
                                }
                                food = {{fx, fy}, "F"};
                            } else {
                                pair<pair<int, int>, string> tail = snake.back(), forwardTail;
                                snake.pop_back();
                                forwardTail = snake.back();
                                if (tail.second == "TL") {
                                    if (forwardTail.second == "BH") {
                                        snake.back().second = "TL";
                                    } else if (forwardTail.second == "CTR") {
                                        snake.back().second = "TU";
                                    } else if (forwardTail.second == "CBR") {
                                        snake.back().second = "TD";
                                    }
                                } else if (tail.second == "TR") {
                                    if (forwardTail.second == "BH") {
                                        snake.back().second = "TR";
                                    } else if (forwardTail.second == "CTL") {
                                        snake.back().second = "TU";
                                    } else if (forwardTail.second == "CBL") {
                                        snake.back().second = "TD";
                                    }
                                } else if (tail.second == "TU") {
                                    if (forwardTail.second == "BV") {
                                        snake.back().second = "TU";
                                    } else if (forwardTail.second == "CBL") {
                                        snake.back().second = "TL";
                                    } else if (forwardTail.second == "CBR") {
                                        snake.back().second = "TR";
                                    }
                                } else if (tail.second == "TD") {
                                    if (forwardTail.second == "BV") {
                                        snake.back().second = "TD";
                                    } else if (forwardTail.second == "CTL") {
                                        snake.back().second = "TL";
                                    } else if (forwardTail.second == "CTR") {
                                        snake.back().second = "TR";
                                    }
                                }
                            }
                            // Working on Head
                            if (head.second == "HL") {
                                snake.front().second = "CTL";
                            } else if (head.second == "HR") {
                                snake.front().second = "CTR"; 
                            } else if (head.second == "HD") {
                                snake.front().second = "BV";
                            }
                            snake.push_front({newHead, "HD"});
                        }
                        break;
                }
            }
        window.clear();
        if (gameOver) {
            string s = to_string(score);
            text.setString("Game Over\nScore\n" + s);
            text.setCharacterSize(30);
            text.setFillColor(sf::Color::Blue);
            window.draw(text);
        } else {
            int x = 0, y = 0;
            for (int i = 0; i < 10; ++i) {
                x = 0;
                for (int j = 0; j < 10; ++j) {
                    sprite.setPosition(x, y);
                    sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
                    if (x == food.first.first and y == food.first.second) {
                        sprite.setTextureRect(sf::IntRect(0, 192, 64, 64));
                    }
                    for (auto itr = snake.begin(); itr != snake.end(); ++itr) {
                        pair<pair<int, int>, string> temp = *itr;
                        if (temp.first.first == x and temp.first.second == y) {
                            if (temp.second == "HU") {
                                sprite.setTextureRect(sf::IntRect(192, 0, 64, 64));
                            } else if (temp.second == "HL") {
                                sprite.setTextureRect(sf::IntRect(192, 64, 64, 64));
                            } else if (temp.second == "HR") {
                                sprite.setTextureRect(sf::IntRect(256, 0, 64, 64));
                            } else if (temp.second == "HD") {
                                sprite.setTextureRect(sf::IntRect(256, 64, 64, 64));
                            } else if (temp.second == "TU") {
                                sprite.setTextureRect(sf::IntRect(256, 192, 64, 64));
                            } else if (temp.second == "TL") {
                                sprite.setTextureRect(sf::IntRect(256, 128, 64, 64));
                            } else if (temp.second == "TR") {
                                sprite.setTextureRect(sf::IntRect(192, 192, 64, 64));
                            } else if (temp.second == "TD") {
                                sprite.setTextureRect(sf::IntRect(192, 128, 64, 64));
                            } else if (temp.second == "CTL") {
                                sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
                            } else if (temp.second == "CTR") {
                                sprite.setTextureRect(sf::IntRect(128, 0, 64, 64));
                            } else if (temp.second == "CBL") {
                                sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
                            } else if (temp.second == "CBR") {
                                sprite.setTextureRect(sf::IntRect(128, 128, 64, 64));
                            } else if (temp.second == "BV") {
                                sprite.setTextureRect(sf::IntRect(128, 64, 64, 64));
                            } else if (temp.second == "BH") {
                                sprite.setTextureRect(sf::IntRect(64, 0, 64, 64));
                            }
                        }
                    }
                    window.draw(sprite);   
                    x += 64;
                }
                y += 64;
            }
        }
        window.display();
    }
    return 0;
}