#ifndef POLLO_H
#define POLLO_H

#include "Animal.h"

namespace UkeleleChicken {

    // Clase Real / Concreta (b, c)
    class Pollo : public Animal {
    private:
        bool esOrganico;

    public:
        Pollo(const std::string& n, int e, bool organico);
        virtual ~Pollo();

        // Sobrescritura obligatoria de los métodos virtuales puros (k)
        virtual void comer() const override;
        virtual void dormir() const override;

        bool getEsOrganico() const;
    };

}

#endif // POLLO_H
