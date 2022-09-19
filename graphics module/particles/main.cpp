#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"
int main(){
    sf::RenderWindow window(sf::VideoMode(400,200),"SFML WORKS!" );
    ParticleSystem particleSystem(500);
    sf::Clock clock;
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type==sf::Event::Closed) window.close();
        }
        window.clear();
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
             particleSystem.setContinous(true);
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        particleSystem.setEmitter(window.mapPixelToCoords(localPosition));
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                particleSystem.setContinous(false);
               sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        particleSystem.setEmitter(window.mapPixelToCoords(localPosition));
        }
        sf::Time elapsed=clock.restart();
        particleSystem.update(elapsed);
        window.draw(particleSystem);
        window.display();
    }
return 0;
}
