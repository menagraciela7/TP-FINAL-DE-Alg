#include "Animal.h"

namespace UkeleleChicken {

    Animal::Animal(const std::string& n, int e) : nombre(n), edad(e) {}
    
    Animal::~Animal() {}

    std::string Animal::getNombre() const {
        return nombre;
    }

    int Animal::getEdad() const {
        return edad;
    }

}
