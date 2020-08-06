#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 640), "Awesome Game");
    sf::Texture texture;
    texture.loadFromFile("image.jpg");
    sf::Sprite sprite;
    sprite.setTexture(texture);
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
            }
        }

        window.clear();
        int x = 0, y = 0;
        for (int i = 0; i < 10; ++i) {
            x = 0;
            for (int j = 0; j < 10; ++j) {
                sprite.setPosition(x, y);
                if (x == 64 and y == 64) {
                    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
                } else if (x == 128 and y == 64) {
                    sprite.setTextureRect(sf::IntRect(64, 0, 64, 64));
                } else if (x == 192 and y == 64) {
                    sprite.setTextureRect(sf::IntRect(192, 192, 64, 64));
                } else if (x == 64 and y == 128) {
                    sprite.setTextureRect(sf::IntRect(256, 64, 64, 64));
                } else {
                    sprite.setTextureRect(sf::IntRect(0, 128, 64, 64));
                } 
                window.draw(sprite);   
                x += 64;
            }
            y += 64;
        }
        window.display();
    }
    return 0;
}