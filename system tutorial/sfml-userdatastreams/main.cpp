#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
int main(){
sf::FileInputStream stream;
stream.open("C:\\Users\\sebastian\\Desktop\\Koala.jpg");


sf::Texture texture;
texture.loadFromStream(stream);
return 0;
}
