#include <SFML/Graphics.hpp>
#include <iostream>
int main(){
    sf::RenderWindow window(sf::VideoMode(400,200),"SFML WORKS!" );
    sf::Font font;
    if(!font.loadFromFile("font.ttf")){
        //error
    }
    int lineSpacing = font.getLineSpacing(60);
    int kerning = font.getKerning('v', 'a', 60);
    std::cout<<lineSpacing<<std::endl;

    std::cout<<kerning<<std::endl;
    sf::Text text;
    text.setFont(font);
    text.setString("Witaj swiecie!\n Hello World!");
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::Red);
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type==sf::Event::Closed) window.close();
        }
        window.clear();
        window.draw(text);
        window.display();
    }
return 0;
}
