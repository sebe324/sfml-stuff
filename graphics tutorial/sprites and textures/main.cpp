#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(400,200),"SFML WORKS!" );
    sf::Texture texture;
    //zaladuj czesc 32x32 obrazu na (10,10)
    if(!texture.loadFromFile("image.png")){
        //error
    }
    texture.setSmooth(true);
    //texture.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,32,32));
    sf::Sprite sprite2;
    sprite2.setPosition(100,25);
    //sprite2.setColor(sf::Color::Green);
    sprite2.setTexture(texture);
    sprite2.setTextureRect(sf::IntRect(32,0,32,32));

    sf::Sprite sprite3;
    sprite3.setTexture(texture);
    sprite3.setTextureRect(sf::IntRect(64,0,32,32));
    sprite3.setOrigin(sf::Vector2f(25.f,25.f));
    sprite3.setPosition(sf::Vector2f(70.f,50.f));
    sprite3.setRotation(45.f);
    //sprite3.setColor(sf::Color::Red);
    sprite3.setScale(sf::Vector2f(0.5f,2.f));
    sprite3.rotate(15.f);

    sprite3.setScale(sf::Vector2f(0.5f,2.f));
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type==sf::Event::Closed) window.close();
        }
        window.clear();
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);
        window.display();
    }
return 0;
}
