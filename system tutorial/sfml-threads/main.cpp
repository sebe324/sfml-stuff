#include <SFML/System.hpp>
#include <iostream>
#include <functional> //std::bind
#include <stdexcept> //runtime_error
sf::Mutex mutex; //MUTual EXclusion zapewnia ze tylko 1 watek jest w stanie odpalic kod, ktory chroni


void func(int x, int y){
    sf::Lock lock(mutex);
        if(y==0){ throw std::runtime_error("Pamietaj cholero nie dziel przez 0!");
        mutex.unlock(); //trzeba odblokowac, jezeli cos moze pojsc nie tak

    }
for (int i=0; i<10; i++){
    std::cout<<"Watek numer 1 : "<<x+i/y<<std::endl;
}
     //sf::sleep(sf::milliseconds(2000)); // zapauzowac watek moze tylko on sam
    }//mutex.unlock();
int main(){
    sf::Thread thread(std::bind(&func,5,2));
    thread.launch();

    //thread.wait(); // czeka az skonczy dzialac watek

    mutex.lock();
    for(int i=0; i<10; i++){
        std::cout<<"Glowny watek"<<std::endl;
    }
    mutex.unlock();
    return 0;
    }

