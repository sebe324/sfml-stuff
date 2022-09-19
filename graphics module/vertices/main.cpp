#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(600,600),"SFML WORKS!" );

    sf::Vertex vertex;

    vertex.position=sf::Vector2f(10.f,50.f);
    vertex.color=sf::Color::Red;
    vertex.texCoords=sf::Vector2f(100.f,100.f);

    sf::Vertex vertex2(sf::Vector2f(60.f,200.f),sf::Color::Red, sf::Vector2f(100.f,100.f));

    std::vector<sf::Vertex> vertices;
    vertices.push_back(vertex);
    vertices.push_back(vertex2);


    sf::VertexArray triangle(sf::Triangles, 3);

    triangle[0].position=sf::Vector2f(210.f,210.f);
    triangle[1].position=sf::Vector2f(310.f,210.f);
    triangle[2].position=sf::Vector2f(310.f,310.f);

    triangle[0].color=sf::Color::Red;
    triangle[1].color=sf::Color::Blue;
    triangle[2].color=sf::Color::Cyan;

    sf::VertexArray triangleStrip(sf::TriangleStrip, 7);
    triangleStrip[0].position=sf::Vector2f(200.f,300.f);
    triangleStrip[1].position=sf::Vector2f(200.f,400.f);
    triangleStrip[2].position=sf::Vector2f(300.f,300.f);
    triangleStrip[3].position=sf::Vector2f(300.f,400.f);
    triangleStrip[4].position=sf::Vector2f(400.f,450.f);
    triangleStrip[5].position=sf::Vector2f(400.f,500.f);
    triangleStrip[6].position=sf::Vector2f(500.f,450.f);
    triangleStrip[7].position=sf::Vector2f(500.f,500.f);
    for(int i=0; i<7; i++){
        triangleStrip[i].color=sf::Color(i*100,i*50,i*20);
    }
            sf::Texture texture;
            if(!texture.loadFromFile("texture.png")){
        //error
    }
    sf::VertexArray quad(sf::Quads, 4);
    quad[0].position=sf::Vector2f(100.f,164.f);
    quad[1].position=sf::Vector2f(100.f,100.f);
    quad[2].position=sf::Vector2f(164.f,100.f);
    quad[3].position=sf::Vector2f(164.f,164.f);
    quad[0].texCoords=sf::Vector2f(0.f,64.f);
    quad[1].texCoords=sf::Vector2f(0.f,0.f);
    quad[2].texCoords=sf::Vector2f(64.f,0.f);
    quad[3].texCoords=sf::Vector2f(64.f,64.f);
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type==sf::Event::Closed) window.close();
        }
        window.clear();
        window.draw(triangle);
        window.draw(&vertices[0],vertices.size(),sf::Lines);
        window.draw(triangleStrip);
        window.draw(quad,&texture);
        window.display();
    }
return 0;
}
