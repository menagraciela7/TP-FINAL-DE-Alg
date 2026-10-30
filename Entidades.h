#ifndef ENTIDADES_H
#define ENTIDADES_H

#include <string>

namespace UkeleleChicken {

    // Entidades simples del negocio de la Boutique para el almacenamiento estático requerido (g)
    class Producto {
    public:
        std::string descripcion;
        double precio;
    };

    class Cliente {
    public:
        std::string nombreCompleto;
        std::string dni;
    };

    class Pedido {
    public:
        int idPedido;
        double total;
    };
}

#endif // ENTIDADES_H
