#include "Vaca.h"
#include <iostream>

namespace UkeleleChicken {

    Vaca::Vaca(const std::string& n, int e, const std::string& corte) 
        : Animal(n, e), tipoCorte(corte) {}

    Vaca::~Vaca() {}

    void Vaca::comer() const {
        std::cout << "La Vaca " << nombre << " esta pastando alfalfa. (Corte objetivo: " << tipoCorte << ")." << std::endl;
    }

    void Vaca::dormir() const {
        std::cout << "La Vaca " << nombre << " duerme placidamente parada en el campo." << std::endl;
    }

    std::string Vaca::getTipoCorte() const {
        return tipoCorte;
    }

}
