#ifndef VACA_H
#define VACA_H

#include "Animal.h"

namespace UkeleleChicken {

    // Clase Real / Concreta (b, c)
    class Vaca : public Animal {
    private:
        std::string tipoCorte; // Atributo propio específico del negocio

    public:
        Vaca(const std::string& n, int e, const std::string& corte);
        virtual ~Vaca();

        // Sobrescritura obligatoria de los métodos virtuales puros (k)
        virtual void comer() const override;
        virtual void dormir() const override;
        
        std::string getTipoCorte() const;
    };

}

#endif // VACA_H
