#include "Pollo.h"
#include <iostream>

namespace UkeleleChicken {

    Pollo::Pollo(const std::string& n, int e, bool organico) 
        : Animal(n, e), esOrganico(organico) {}

    Pollo::~Pollo() {}

    void Pollo::comer() const {
        std::cout << "El Pollo " << nombre << " esta picoteando maiz " 
                  << (esOrganico ? "100% organico" : "industrial") << "." << std::endl;
    }

    void Pollo::dormir() const {
        std::cout << "El Pollo " << nombre << " duerme en el gallinero de la Boutique." << std::endl;
    }

    bool Pollo::getEsOrganico() const {
        return esOrganico;
    }

}
