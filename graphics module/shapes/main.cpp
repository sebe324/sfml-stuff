#include <SFML/Graphics.hpp>
#include <math.h>
class EllipseShape : public sf::Shape{
public:

    explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0.f,0.f)) :
        m_radius(radius){
        update();
        }
        void setRadius(const sf::Vector2f& radius){
            m_radius=radius;
            update();
        }
        const sf::Vector2f& getRadius() const{
        return m_radius;
        }
        virtual std::size_t getPointCount() const{
        return 30;
        }
        virtual sf::Vector2f getPoint(std::size_t index) const{
        static const float pi=3.141592654f;

        float angle = index * 2 * pi / getPointCount() - pi / 2;
        float x=std::cos(angle)*m_radius.x;
        float y=std::sin(angle) * m_radius.y;

        return sf::Vector2f(m_radius.x+x,m_radius.y+y);
        }
private:
    sf::Vector2f m_radius;
};

int main(){
    sf::ContextSettings settings;
    settings.antialiasingLevel=5;

    sf::RenderWindow window(sf::VideoMode(500,500),"SFML WORKS!", sf::Style::Default, settings );
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color(250,150,100));
    sf::RectangleShape shape2({64,64});
    sf::Texture texture;
    if(!texture.loadFromFile("texture.png")){
        //error
    }
    shape2.setTexture(&texture);
    shape2.setTextureRect(sf::IntRect(10,10,20,20));

    sf::CircleShape triangle(80.f, 3);
    sf::CircleShape square(80.f,4);
    sf::CircleShape octagon(80.f, 8);

    triangle.setFillColor(sf::Color::Blue);
    square.setFillColor(sf::Color::Magenta);
    octagon.setFillColor(sf::Color::Cyan);
    triangle.setPosition(100.f,100.f);
    square.setPosition(300.f,250.f);
    octagon.setPosition(180.f,120.f);

    sf::ConvexShape convex;

    convex.setPointCount(5);
    convex.setPoint(0, sf::Vector2f(70.f,70.f));
    convex.setPoint(1, sf::Vector2f(220.f,80.f));
    convex.setPoint(2, sf::Vector2f(190.f,160.f));
    convex.setPoint(3, sf::Vector2f(100.f,170.f));
    convex.setPoint(4, sf::Vector2f(70.f,120.f));
    convex.setFillColor(sf::Color::Yellow);

    sf::Vertex line[]={
        sf::Vertex(sf::Vector2f(400.f,0.f)),
        sf::Vertex(sf::Vector2f(0.f,400.f))
    };

    EllipseShape ellipse(sf::Vector2f(50.f,10.f));
    ellipse.setFillColor(sf::Color::White);
    ellipse.setPosition(300.f, 0.f);
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type==sf::Event::Closed) window.close();
        }
        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.draw(triangle);
        window.draw(square);
        window.draw(octagon);
        window.draw(convex);
        window.draw(line,2,sf::Lines);
        window.draw(ellipse);
        window.display();
    }
return 0;
}
