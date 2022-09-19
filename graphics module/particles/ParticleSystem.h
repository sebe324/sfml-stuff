#include <SFML/Graphics.hpp>
class ParticleSystem : public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    struct Particle{
    sf::Vector2f velocity;
    sf::Time lifetime;
    };
    void resetParticle(std::size_t index);
    void resetParticles();
    std::vector<Particle> mParticles;
    sf::VertexArray mVertices;
    sf::Time mLifetime;
    sf::Vector2f mEmitter;
    bool continous;
public:
    ParticleSystem(unsigned int amount, bool c=true);
    void setEmitter(sf::Vector2f position);
    void update(sf::Time elapsed);
    void setContinous(bool c);
};
