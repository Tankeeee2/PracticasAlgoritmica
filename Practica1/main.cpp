#include <iostream>
#include "medio_nivel.hpp"

int main()
{
    int opcion;

    do
    {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Ordenacion por Seleccion\n";
        std::cout << "2. Ordenacion Quicksort\n";
        std::cout << "3. Determinante Iterativo\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";

        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            ordenacionSeleccion();
            break;
        case 2:
            ordenacionQuicksort();
            break;
        case 3:
            determinanteIterativo();
            break;
        case 0:
            std::cout << "Programa finalizado.\n";
            break;
        default:
            std::cout << "Opción no válida.\n";
        }
    } while (opcion != 0);

    return 0;
}
