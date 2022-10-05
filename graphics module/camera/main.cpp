#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
    sf::RenderWindow window(sf::VideoMode(400,400),"SFML WORKS!" );
      sf::View view1(sf::Vector2f(0.f,0.f),sf::Vector2f(400.f,400.f));
    window.setView(view1);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::RectangleShape shape2({100,100});
    shape2.setFillColor(sf::Color::Red);
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseWheelScrolled:
            if(event.mouseWheelScroll.delta==1)
            view1.zoom(0.25f);
            else view1.zoom(4.f);
            break;
        }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            view1.rotate(-.03f);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            view1.rotate(.03f);
        window.clear();
        window.setView(view1);
        window.draw(shape);
        window.draw(shape2);
        window.display();
    }
return 0;
}
