#include <iostream>
#include "matriz.hpp"

int main() {
    Matriz A(2, 2);
    Matriz B(2, 2);

    A.setElemento(0, 0, 1); A.setElemento(0, 1, 2);
    A.setElemento(1, 0, 3); A.setElemento(1, 1, 4);

    B.setElemento(0, 0, 5); B.setElemento(0, 1, 6);
    B.setElemento(1, 0, 7); B.setElemento(1, 1, 8);

    std::cout << "Matriz A:" << std::endl;
    std::cout << A << std::endl;

    std::cout << "Matriz B:" << std::endl;
    std::cout << B << std::endl;

    Matriz C = A * B;

    std::cout << "Matriz C (Resultado de A * B):" << std::endl;
    std::cout << C << std::endl;
    
    std::cout << "El resultado esperado para C es:" << std::endl;
    std::cout << "               19.0000                22.0000 " << std::endl;
    std::cout << "               43.0000                50.0000 " << std::endl;

    return 0;
}
