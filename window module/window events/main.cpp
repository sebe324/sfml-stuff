#include <SFML/Window.hpp>
#include <iostream>
int main(){
    sf::Window window(sf::VideoMode(400,200),"SFML WORKS!" );

    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
                if(event.key.code==sf::Keyboard::Escape){
                    std::cout<<"kliknieto klawisz escape"<<std::endl;
                    std::cout<<"control: "<<event.key.control<<std::endl;
                    std::cout<<"alt: "<<event.key.alt<<std::endl;
                    std::cout<<"shift: "<<event.key.shift<<std::endl;
                    std::cout<<"system: "<<event.key.system<<std::endl;
                }
            break;
        case sf::Event::LostFocus:
            //wstrzymaj gre
            break;
        case sf::Event::GainedFocus:
            //wznow gre
            break;
              case sf::Event::TextEntered:
            std::cout<<"wpisany znak ASCII: "<<static_cast<char>(event.text.unicode)<<std::endl;
            break;
              case sf::Event::MouseWheelScrolled:
                    if(event.mouseWheelScroll.wheel==sf::Mouse::VerticalWheel) std::cout<<"wheel type: vertical" << std::endl;
                    else if(event.mouseWheelScroll.wheel=sf::Mouse::HorizontalWheel) std::cout<<"wheel type: horizontal" << std::endl;
                    else std::cout<<"wheel type: unknown"<<std::endl;
                break;
              case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button==sf::Mouse::Left){
                    std::cout<<"kliknieto lewy przycisk myszki"<<std::endl;
                    std::cout<<"x: "<<event.mouseButton.x<<std::endl;
                    std::cout<<"y: "<<event.mouseButton.y<<std::endl;
                }
                else if(event.mouseButton.button==sf::Mouse::Right){
                    std::cout<<"kliknieto prawy przycisk myszki"<<std::endl;
                    std::cout<<"x: "<<event.mouseButton.x<<std::endl;
                    std::cout<<"y: "<<event.mouseButton.y<<std::endl;
                }
              case sf::Event::MouseButtonReleased:
                    if(event.mouseButton.button==sf::Mouse::Left) std::cout<<"puszczono lewy przycisk myszki"<<std::endl;
                    else if(event.mouseButton.button==sf::Mouse::Right) std::cout<<"puszczono prawy przycisk myszki"<<std::endl;
                break;
              case sf::Event::MouseMoved:
                std::cout<<"nowa pozycja x myszki: "<<event.mouseMove.x<<std::endl;
                std::cout<<"nowa pozycja y myszki: "<<event.mouseMove.y<<std::endl;
                break;
              case sf::Event::MouseEntered: std::cout<<"Kursor jest w grze"<<std::endl; break;
              case sf::Event::MouseLeft: std::cout<<"Kursor jest poza gra"<<std::endl; break;

              case sf::Event::JoystickButtonPressed:
                std::cout<<"kliknieto guzik na padzie! "<<std::endl;
                std::cout<<"id pada: "<<event.joystickButton.joystickId<<std::endl;
                std::cout<<"guzik: "<<event.joystickButton.button<<std::endl;
                break;
              case sf::Event::JoystickMoved:
                if(event.joystickMove.axis==sf::Joystick::X){
                    std::cout<<"Poruszono galka od pada! "<<std::endl;
                    std::cout<<"id pada: "<<event.joystickMove.joystickId<<std::endl;
                    std::cout<<"nowa pozycja: "<<event.joystickMove.position<<std::endl;
                }
                break;
              case sf::Event::JoystickConnected:
                    std::cout<<"Podlaczono nowy pad! "<<event.joystickConnect.joystickId<<std::endl;
                break;
              case sf::Event::JoystickDisconnected:
                    std::cout<<"Odlaczono pad! "<<event.joystickConnect.joystickId<<std::endl;
                break;
            }

        }
    }
return 0;
}
