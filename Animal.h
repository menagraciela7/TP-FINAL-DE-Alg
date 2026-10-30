#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

namespace UkeleleChicken {

    // Clase Abstracta Base (c, h)
    class Animal {
    protected:
        std::string nombre; // Atributos encapsulados/protegidos (d)
        int edad;

    public:
        Animal(const std::string& n, int e);
        virtual ~Animal(); // Destructor virtual esencial para polimorfismo

        // Métodos comunes con implementación compartida (d)
        std::string getNombre() const;
        int getEdad() const;

        // Métodos virtuales puros: definen el comportamiento polimórfico (h)
        virtual void comer() const = 0;
        virtual void dormir() const = 0;
    };

}

#endif // ANIMAL_H
