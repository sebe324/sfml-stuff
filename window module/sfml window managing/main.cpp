#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
int main(){
 sf::Window window(sf::VideoMode(800,600),"Moje okno"); //trzeci parametr jest opcjonalny, mozna dodac jakies style np fullscreen
 /*
 lub mozna tak:
 sf::Window window;

 window.create(sf::VideoMode(800,600),"Nazwa");
 */
window.setPosition(sf::Vector2i(10,50));

window.setSize(sf::Vector2u(640,480));

window.setTitle("okno SFML");

sf::Vector2u wsize = window.getSize();
unsigned int width=wsize.x;
unsigned int height=wsize.y;

bool focus=window.hasFocus();

window.setVerticalSyncEnabled(true); //maxfps to refresh rate monitora

 while (window.isOpen()){
    //sprawdza czy stalo sie jakies wydarzenie po ostatniej iteracji petli

    sf::Event event;
    while(window.pollEvent(event)){ //ta petla jest wazna!
        if(event.type == sf::Event::Closed) window.close();
    }
 }

return 0;
}
