#include "auxiliares.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>

void rellenarVector(std::vector<int> &v)
{
    srand(time(NULL));
    for (size_t i = 0; i < v.size(); i++)
    {
        v[i] = rand() % 10000000;
    }
    return;
}

bool estaOrdenado(const std::vector<int> &v)
{
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i - 1])
        {
            return false;
        }
    }
    return true;
}

void fichero(std::vector<double> &tiemposReales, std::vector<double> &numeroElementos)
{
    std::string t, n, escribir;
    std::ofstream f("tiemposReales.txt");
    for (size_t i = 0; i < tiemposReales.size(); i++)
    {
        t = std::to_string(tiemposReales[i]);
        n = std::to_string(numeroElementos[i]);
        escribir = t + " " + n + "\n";
        f.write(escribir.data(), escribir.size());
    }
}

void datosFinales(const std::vector<double> &numeroElementos, const std::vector<double> &tiemposReales, const std::vector<double> &tiemposEstimados)
{
    std::string t, n, e, escribir;
    std::ofstream f("datosFinales.txt");
    for (size_t i = 0; i < tiemposReales.size(); i++)
    {
        n = std::to_string(numeroElementos[i]);
        t = std::to_string(tiemposReales[i]);
        e = std::to_string(tiemposEstimados[i]);
        escribir = n + " " + t + " " + e + "\n";
        f.write(escribir.data(), escribir.size());
    }
}

void rellenarMatriz(std::vector<std::vector<double>> &M)
{
    srand(time(NULL));
    for (unsigned int i = 0; i < M.size(); i++)
    {
        for (unsigned int j = 0; j < M.size(); j++)
        {
            M[i][j] = (rand() % 1000);
            M[i][j] = M[i][j] / 10000 + 0.95;
        }
    }
}
