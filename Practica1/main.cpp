#include "ClaseTiempo.h"
#include "sistemaEcuaciones.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void ordenacionSeleccion();
void ordenacionQuicksort();
void determinanteIterativo();

int main() {
  int opcion;

  do {
    cout << "\n=== MENU PRINCIPAL ===\n";
    cout << "1. Ordenación por Selección\n";
    cout << "2. Ordenación Quicksort\n";
    cout << "3. Determinante Iterativo\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opción: ";

    cin >> opcion;

    switch (opcion) {
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
      cout << "Programa finalizado.\n";
      break;
    default:
      cout << "Opción no válida.\n";
    }
  } while (opcion != 0);

  return 0;
}

// Implementaciones temporales de las funciones
void ordenacionSeleccion() {
  int nMin = 1000;
  int nMax = 5000;
  int incremento = 100;
  int repeticiones = 5;

  vector<double> tiemposReales;
  vector<double> numeroElementos;
  vector<double> a;
  vector<double> tiemposEstimados;

  tiemposOrdenacionSeleccion(nMin, nMax, incremento, repeticiones, tiemposReales, numeroElementos);

  ajustePolinomico(numeroElementos, tiemposReales, a);

  calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

  double r2 = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

  cout << "Ecuación de la curva ajustada: t(n) = " << a[0] << " + " << a[1] << "n + " << a[2] << "n^2" << endl;
  cout << "Coeficiente de determinación (R^2): " << r2 << endl;

  double n_estimar;
  do {
    cout << "\nIntroduce un tamaño de ejemplar (n) para estimar el tiempo (0 para salir): ";
    cin >> n_estimar;
    if (n_estimar > 0) {
      double tiempo_estimado = calcularTiempoEstimadoPolinomico(n_estimar, a);
      cout << "Para n = " << n_estimar << ", el tiempo estimado es de " << tiempo_estimado << " microsegundos." << endl;
    }
  } while (n_estimar != 0);
}

void ordenacionQuicksort() {
  cout << "Función ordenación quicksort \n";
}

void determinanteIterativo() {
  cout << "Función determinante iterativo \n";
}