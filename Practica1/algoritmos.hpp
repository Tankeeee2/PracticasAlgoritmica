#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP

#include <vector>

// From detRecursivo.cpp
double algrecursivo(std::vector<std::vector<double>> &M, int b);

void ordenacionSeleccion(std::vector<int> &v);
void ordenacionQuicksort(std::vector<int> &v);
double determinanteIterativo(std::vector<std::vector<double>> &M);

#endif // ALGORITMOS_HPP
