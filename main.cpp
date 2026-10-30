#include <iostream>
#include "Animal.h"
#include "Vaca.h"
#include "Pollo.h"
#include "Entidades.h"

using namespace UkeleleChicken;

int main() {
    // g. Carga inicial estática de Productos (5), Clientes (3) y Pedidos (2) mediante Arrays
    Producto productos[5] = {
        {"Ojo de Bife", 12000.0},
        {"Pechuga de Pollo", 4500.0},
        {"Asado de Tira", 9500.0},
        {"Pata y Muslo", 3800.0},
        {"Vacio", 11000.0}
    };

    Cliente clientes[3] = {
        {"Juan Perez", "20123456"},
        {"Maria Gomez", "25987654"},
        {"Carlos Lopez", "30456123"}
    };

    Pedido pedidos[2] = {
        {101, 16500.0},
        {102, 8300.0}
    };

    // j. Arreglo de Punteros del tipo base abstracta "Animal"
    const int MAX_ANIMALES = 5;
    Animal* inventarioAnimales[MAX_ANIMALES] = {nullptr};
    int contadorAnimales = 0;

    int opcion = 0;
    do {
        // f. Menú para interactuar en tiempo de ejecución
        std::cout << "\n=== MENU BOUTIQUE UKELELE CHICKEN ===" << std::endl;
        std::cout << "1. Registrar una Vaca (Objeto Concreto Vaca)" << std::endl;
        std::cout << "2. Registrar un Pollo (Objeto Concreto Pollo)" << std::endl;
        std::cout << "3. Simular Rutinas Polimorficas (Comer / Dormir)" << std::endl;
        std::cout << "4. Ver Listados Estaticos (Productos, Clientes, Pedidos)" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Elija una opcion: ";
        std::cin >> opcion;

        if (opcion == 1 || opcion == 2) {
            if (contadorAnimales >= MAX_ANIMALES) {
                std::cout << "Inventario de animales lleno." << std::endl;
                continue;
            }

            std::string nombre;
            int edad;
            std::cout << "Ingrese nombre del animal: ";
            std::cin >> nombre;
            std::cout << "Ingrese edad: ";
            std::cin >> edad;

            if (opcion == 1) {
                std::string corte;
                std::cout << "Ingrese tipo de corte destinado: ";
                std::cin >> corte;
                // j. Puntero Animal apuntando a Vaca
                inventarioAnimales[contadorAnimales] = new Vaca(nombre, edad, corte);
            } else {
                int organicoInput;
                std::cout << "Es organico? (1: Si / 0: No): ";
                std::cin >> organicoInput;
                // j. Puntero Animal apuntando a Pollo
                inventarioAnimales[contadorAnimales] = new Pollo(nombre, edad, organicoInput == 1);
            }
            contadorAnimales++;
            std::cout << "Animal registrado exitosamente en la coleccion base." << std::endl;
        }
        else if (opcion == 3) {
            if (contadorAnimales == 0) {
                std::cout << "No hay animales registrados para simular rutinas." << std::endl;
            } else {
                std::cout << "\n--- EJECUTANDO COMPORTAMIENTO POLIMORFICO ---" << std::endl;
                // k, i. Recorre el Array ejecutando llamadas genéricas por Polimorfismo
                for (int i = 0; i < contadorAnimales; ++i) {
                    std::cout << "Animal [" << i + 1 << "]: " << inventarioAnimales[i]->getNombre() 
                              << " | Edad: " << inventarioAnimales[i]->getEdad() << " anos." << std::endl;
                    
                    // Llamadas idénticas e independientes del tipo subyacente real
                    inventarioAnimales[i]->comer();
                    inventarioAnimales[i]->dormir();
                    std::cout << "---------------------------------------------" << std::endl;
                }
            }
        }
        else if (opcion == 4) {
            std::cout << "\n--- LISTA DE PRODUCTOS ---" << std::endl;
            for(int i = 0; i < 5; i++) {
                std::cout << "- " << productos[i].descripcion << " | Precio: $" << productos[i].precio << std::endl;
            }
            std::cout << "\n--- LISTA DE CLIENTES ---" << std::endl;
            for(int i = 0; i < 3; i++) {
                std::cout << "- " << clientes[i].nombreCompleto << " | DNI: " << clientes[i].dni << std::endl;
            }
            std::cout << "\n--- LISTA DE PEDIDOS ---" << std::endl;
            for(int i = 0; i < 2; i++) {
                std::cout << "- Pedido #" << pedidos[i].idPedido << " | Monto: $" << pedidos[i].total << std::endl;
            }
        }

    } while (opcion != 5);

    // Liberación responsable de la memoria dinámica instanciada en tiempo de ejecución
    for (int i = 0; i < contadorAnimales; ++i) {
        delete inventarioAnimales[i];
    }

    std::cout << "\nSistema cerrado correctamente. Saludos a Santa Clara del Mar!" << std::endl;
    return 0;
}
