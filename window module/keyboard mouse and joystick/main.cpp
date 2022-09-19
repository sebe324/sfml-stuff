#include <SFML/Window.hpp>
#include <iostream>
int main(){
    sf::Window window(sf::VideoMode(500,500),"Input devices");
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed) window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) std::cout<<"idz w lewo"<<std::endl;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){std::cout<<"strzelaj"<<std::endl;
        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        std::cout<<"x: "<<localPosition.xstd::endl;
        std::cout<<"y: "<<localPosition.y<<std::endl;
        sf::Vector2i globalPosition = sf::Mouse::getPosition();
        }
        //sf::Mouse::setPosition(sf::Vector2i(10,50)); Uwaga bo myszka moze utknac xd
        if(sf::Joystick::isConnected(0)){
             unsigned int ButtonCount=sf::Joystick::getButtonCount(0);

             //sprawdz czy joystick 0 posiada oœ 0
             bool hasZ=sf::Joystick::hasAxis(0,sf::Joystick::Z);
        }
        if(sf::Joystick::isButtonPressed(0,1)){
            std::cout<<"ognia! "<<std::endl;
            float x = sf::Joystick::getAxisPosition(0,sf::Joystick::X);
            float y = sf::Joystick::getAxisPosition(0,sf::Joystick::Y);
        }
    }
return 0;
}
