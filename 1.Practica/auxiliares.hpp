#ifndef AUXILIARES_HPP
#define AUXILIARES_HPP

#include <vector>
#include <string>


void rellenarVector(std::vector<int> &v);
bool estaOrdenado(const std::vector<int> &v);
void fichero(std::vector<double> &tiemposReales, std::vector<double> &numeroElementos);
void datosFinales(const std::vector<double> &numeroElementos, const std::vector<double> &tiemposReales, const std::vector<double> &tiemposEstimados);


void rellenarMatriz(std::vector<std::vector<double>> &M);

#endif // AUXILIARES_HPP
