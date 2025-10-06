#include "medio_nivel.hpp"
#include "tiempos.hpp"
#include "ClaseTiempo.h"
#include "algoritmos.hpp"
#include "auxiliares.hpp"
#include <iostream>
#include <vector>

void ordenacionSeleccion()
{
    int nMin = 1000;
    int nMax = 5000;
    int inc = 500;
    int repeat = 10;
    double coefDet;
    double n_estimar = 0;

    std::vector<double> tiemposReales;
    std::vector<double> numeroElementos;
    std::vector<double> a;
    std::vector<double> tiemposEstimados;

    std::cout << "nMin= ";
    std::cin >> nMin;
    std::cout << "nMax= ";
    std::cin >> nMax;
    std::cout << "inc= ";
    std::cin >> inc;
    std::cout << "repeat= ";
    std::cin >> repeat;

    tiemposOrdenacionSeleccion(nMin, nMax, inc, repeat, tiemposReales, numeroElementos);

    fichero(tiemposReales, numeroElementos);

    ajustePolinomico(numeroElementos, tiemposReales, a);

    calcularTiemposEstimadosPolinomico(numeroElementos, a, tiemposEstimados);

    coefDet = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    datosFinales(numeroElementos, tiemposReales, tiemposEstimados);

    std::cout << "Ecuacion curva ajustada= " << a[0] << "+" << a[1] << "*n+" << a[2] << "*n^2" << std::endl;
    std::cout << "Coeficiente de determinacion= " << coefDet << std::endl;
    std::cout << "Introduce un tamaño para la estimación de tiempo (0 para omitir): ";
    std::cin >> n_estimar;
    if (n_estimar != 0)
    {
        double tiempo = calcularTiempoEstimadosPolinomico(n_estimar, a);
        double seg = tiempo / 1000000;
        double min = seg / 60;
        double dias = min / (24 * 60);
        double years = dias / 365;
        std::cout << "Tiempo estimado= " << years << " años, " << dias << " dias, " << min << " min, " << seg << " seg" << std::endl;
    }
}

void ordenacionQuicksort()
{
    ordenacionQuickSort();
}

void determinanteIterativo()
{
    determinanteRecursivo();
}
