#ifndef TIEMPOS_HPP
#define TIEMPOS_HPP

#include <vector>

// High-level functions from main.cpp in reference
void ordenacionQuickSort();
void determinanteRecursivo();

void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, std::vector<double> &tiemposReales, std::vector<double> &numeroElementos);

// Functions from qsort.cpp
void ajusteNlogN(const std::vector<double> &numeroElementos, std::vector<double> &tiemposReales, std::vector<double> &a);
void calcularTiemposEstimadoNlogN(const std::vector<double> &numeroElementos, const std::vector<double> &a, std::vector<double> &tiemposEstimados);
double calcularTiempoEstimadoNlogN(const double &n, std::vector<double> &a);
double sumatorio(const std::vector<double> &n, const std::vector<double> &t, int expN, int expT);
double calcularCoeficienteDeterminacion(const std::vector<double> &tiemposReales, const std::vector<double> &tiemposEstimados);

// Functions from detRecursivo.cpp
void ajusteFactorial(const std::vector<double> &n, std::vector<double> &tiemposReales, std::vector<double> &a);
void calcularTiemposEstimadosFactorial(const std::vector<double> &n, std::vector<double> &tiemposReales, std::vector<double> &a, std::vector<double> &tiemposEstimados);
double calcularTiempoEstimadosFactorial(const double &n, std::vector<double> &a);

// Functions from detIterativo.cpp
void ajustePolinomico(std::vector<double> &n, std::vector<double> &tiemposReales, std::vector<double> &a);
void calcularTiemposEstimadosPolinomico(const std::vector<double> &n, std::vector<double> &a, std::vector<double> &tiemposEstimados);
double calcularTiempoEstimadosPolinomico(const double &n, const std::vector<double> &a);
void calcularMatrices(const std::vector<double> &numeroElementos, const std::vector<double> &tiemposReales, int ordenMatrizSistema, std::vector<std::vector<double>> &matrizCoeficientes, std::vector<std::vector<double>> &matrizTerminosIndependientes);

#endif // TIEMPOS_HPP
