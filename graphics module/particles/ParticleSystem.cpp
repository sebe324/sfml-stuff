#include "ParticleSystem.h"
#include <math.h>
#include <cstdlib>
ParticleSystem::ParticleSystem(unsigned int amount, bool c) :
    mParticles(amount), mVertices(sf::Points, amount), mLifetime(sf::seconds(3.f)),mEmitter(0.f,0.f){
        continous=c;
    }
void ParticleSystem::setEmitter(sf::Vector2f position){
mEmitter=position;
}
void ParticleSystem::update(sf::Time elapsed){
for(std::size_t i=0; i<mParticles.size(); ++i){
Particle &p = mParticles[i];
p.lifetime-=elapsed;

if(p.lifetime<=sf::Time::Zero && continous) resetParticle(i);

mVertices[i].position+=p.velocity*elapsed.asSeconds();

float fraction = p.lifetime.asSeconds()/mLifetime.asSeconds();
mVertices[i].color.a=static_cast<sf::Uint8>(fraction*255);
}
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const{
states.transform*=getTransform();
states.texture=NULL;
target.draw(mVertices, states);
}

void ParticleSystem::resetParticle(std::size_t index){
float angle=(std::rand()%360)*3.14/180.f;
float speed=(std::rand()%10)+50.f;
mParticles[index].velocity=sf::Vector2f(std::cos(angle)*speed, std::sin(angle)*speed);
mParticles[index].lifetime=sf::milliseconds(std::rand()%500+1000);

mVertices[index].position=mEmitter;
}

void ParticleSystem::setContinous(bool c){
    resetParticles();
continous=c;
}
void ParticleSystem::resetParticles(){
for(std::size_t i=0; i<mParticles.size(); ++i) resetParticle(i);
}
