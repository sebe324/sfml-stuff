#include "tileMap.h"

//sciezka do pliku, rozmiar jednego bloku, wskaznik do tablicy, szerokosc i wysokosc mapy.
bool TileMap::load(const std::string& tileset,
sf::Vector2u tileSize, const int* tiles,
unsigned int width, unsigned int height){
    //ladowanie mapy
    if(!mTileset.loadFromFile(tileset)) return false;

    //ustawia typ tablicy vertexow na quads
    mVertices.setPrimitiveType(sf::Quads);
    //zmienia rozmiar tablicy
    mVertices.resize(width*height*4);

    //petle, ktore obsluguja kazdy kwadrat
    for(unsigned int i = 0; i<width; ++i)
    for(unsigned int j=0; j<height; ++j){
            //tablica jest jakby dwuwymiarowa, ale jest zapisana jako jednowymiarowa
            //dlatego trzeba dodac aktualna kolumne i iloraz wiersz razy szerokosc aby pobrac wartosc danego pola
        int tileNumber = tiles[i+j*width];

            //znajduje pozycje textury w pliku
        int tu=tileNumber % (mTileset.getSize().x / tileSize.x);
        int tv= tileNumber / (mTileset.getSize().x / tileSize.x);

        sf::Vertex* quad = &mVertices[(i+j*width)*4];

        //definiuje 4 wierzcholki czworokata
        quad[0].position=sf::Vector2f(i*tileSize.x,j*tileSize.y);
        quad[1].position=sf::Vector2f((i+1)*tileSize.x, j*tileSize.y);
        quad[2].position=sf::Vector2f((i+1)*tileSize.x, (j+1)*tileSize.y);
        quad[3].position=sf::Vector2f(i*tileSize.x, (j+1)*tileSize.y);

        //definiuje 4 koordynaty tekstury
        quad[0].texCoords=sf::Vector2f(tu*tileSize.x, tv*tileSize.y);
        quad[1].texCoords=sf::Vector2f((tu+1)*tileSize.x, tv+tileSize.y);
        quad[2].texCoords=sf::Vector2f((tu+1)*tileSize.x, (tv+1)*tileSize.y);
        quad[3].texCoords=sf::Vector2f(tu*tileSize.x, (tv+1)*tileSize.y);
    }
    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const{
states.transform*=getTransform();
states.texture = &mTileset;
target.draw(mVertices, states);
}
