#include <SFML/Graphics.hpp>
int main(){
    sf::RenderWindow window(sf::VideoMode(800,600),"SFML WORKS!" );
    sf::RenderTexture renderTexture;
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(50,-50);

    if(!renderTexture.create(500,500)){
        //error
    }
    renderTexture.clear();
    renderTexture.draw(shape);
    renderTexture.display();


    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
        case sf::Event::Closed:
            window.close();
            break;
            }
        }
        const sf::Texture& texture=renderTexture.getTexture();
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }
return 0;
}
