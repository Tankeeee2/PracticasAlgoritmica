#include "tiempos.hpp"
#include "ClaseTiempo.h"
#include "auxiliares.hpp"
#include "algoritmos.hpp"
#include "sistemaEcuaciones.hpp"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm> 


void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, std::vector<double> &tiemposReales, std::vector<double> &numeroElementos)
{
    Clock time;
    double tiempo = 0;

    for (int i = nMin; i <= nMax; i = i + incremento)
    {
        tiempo = 0;
        for (int j = 0; j < repeticiones; j++)
        {
            std::vector<int> v(i);
            rellenarVector(v);
            time.start();
            ordenacionSeleccion(v);
            if (time.isStarted())
            {
                time.stop();
            }
            if (estaOrdenado(v) == false)
            {
                std::cout << "Error, no se ha realizado la ordenacion" << std::endl;
            }
            tiempo = time.elapsed() + tiempo;
        }
        tiempo = tiempo / repeticiones;
        tiemposReales.push_back(tiempo);
        numeroElementos.push_back(i);
    }
}

void tiemposOrdenacionQuicksort(int nMin, int nMax, int incremento, int repeticiones, std::vector<double> &tiemposReales, std::vector<double> &numeroElementos)
{
    Clock time;
    double tiempo = 0;

    for (int i = nMin; i <= nMax; i = i + incremento)
    {
        tiempo = 0;
        for (int j = 0; j < repeticiones; j++)
        {
            std::vector<int> v(i);
            rellenarVector(v);
            time.start();
            ordenacionQuicksort(v);
            if (time.isStarted())
            {
                time.stop();
            }
            if (estaOrdenado(v) == false)
            {
                std::cout << "Error, no se ha realizado la ordenacion" << std::endl;
            }
            tiempo = time.elapsed() + tiempo;
        }
        tiempo = tiempo / repeticiones;
        tiemposReales.push_back(tiempo);
        numeroElementos.push_back(i);
    }
}

// Esta función se mantiene para compatibilidad pero no se usa directamente
// La lógica está en medio_nivel.cpp
void ordenacionQuickSort()
{
    // Función vacía - la lógica está en medio_nivel.cpp
}

void tiemposDeterminanteIterativo(int nMin, int nMax, int incremento, std::vector<double> &tiemposReales, std::vector<double> &numeroElementos)
{
    Clock time;
    double tiempo = 0;

    for (int i = nMin; i <= nMax; i = i + incremento)
    {
        std::vector<std::vector<double>> M(i, std::vector<double>(i));
        rellenarMatriz(M);
        time.start();
        double det = determinanteIterativo(M);
        if (time.isStarted())
        {
            time.stop();
        }
        tiempo = time.elapsed();
        tiemposReales.push_back(tiempo);
        numeroElementos.push_back(i);
    }
}

void determinanteRecursivo()
{
    Clock time;

    int nMin = 2;
    int nMax = 10;
    int inc = 1;
    int k = 0;
    double tiempo = 0;
    double det = 0;
    double coefDet;
    double seg;
    double min;
    double dias;
    double years;

    std::vector<std::vector<double>> M;
    std::vector<std::vector<double>> inv;
    std::vector<double> tiemposReales;
    std::vector<double> n;
    std::vector<double> a;
    std::vector<double> tiemposEstimados;

    std::cout << "nMin= ";
    std::cin >> nMin;
    std::cout << "nMax= ";
    std::cin >> nMax;
    std::cout << "inc= ";
    std::cin >> inc;

    for (int i = nMin; i <= nMax; i = i + inc)
    {

        M = std::vector<std::vector<double>>(i, std::vector<double>(i));
        rellenarMatriz(M);
        time.start();
        det = algrecursivo(M, i);

        if (time.isStarted())
        {
            time.stop();
        }
        std::cout << "detM[" << i << "][" << i << "]= " << det << std::endl;

        tiempo = time.elapsed() + tiempo;
        tiemposReales.push_back(tiempo);
        n.push_back(i);
    }

    fichero(tiemposReales, n);

    ajusteFactorial(n, tiemposReales, a);

    calcularTiemposEstimadosFactorial(n, tiemposReales, a, tiemposEstimados);

    coefDet = calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

    datosFinales(n, tiemposReales, tiemposEstimados);

    std::cout << "Ecuacion curva ajustada= " << a[0] << "+" << a[1] << "*n!" << std::endl;
    std::cout << "Coeficiente de determinacion= " << coefDet << std::endl;

    do
    {
        std::cout << "Estimacion de tiempos(Si->Introduce un tamaño/No->tamaño=0" << std::endl;
        std::cin >> k;
        if (k != 0)
        {
            tiempo = calcularTiempoEstimadosFactorial(k, a);
            seg = tiempo / 1000000;
            min = seg / 60;
            dias = min / (24 * 60);
            years = dias / 365;
            std::cout << "Tiempo estimado= " << years << " años, " << dias << " dias, " << min << " min, " << seg << " seg" << std::endl;
        }
    } while (k != 0);
}

void ajusteNlogN(const std::vector<double> &numeroElementos, std::vector<double> &tiemposReales, std::vector<double> &a)
{
    std::vector<std::vector<double>> A;
    std::vector<std::vector<double>> B;
    std::vector<std::vector<double>> X;
    std::vector<double> z;
    int n = 2;
    A = std::vector<std::vector<double>>(n, std::vector<double>(n));
    B = std::vector<std::vector<double>>(n, std::vector<double>(1));
    X = std::vector<std::vector<double>>(n, std::vector<double>(1));

    for (size_t i = 0; i < numeroElementos.size(); i++)
    {
        z.push_back(numeroElementos[i] * log10(numeroElementos[i]));
    }

    A[0][0] = numeroElementos.size();
    A[0][1] = sumatorio(z, tiemposReales, 1, 0);
    A[1][0] = A[0][1];
    A[1][1] = sumatorio(z, tiemposReales, 2, 0);
    std::cout << "A= " << A[0][0] << ", " << A[0][1] << ", " << A[1][0] << ", " << A[1][1] << std::endl;

    B[0][0] = sumatorio(z, tiemposReales, 0, 1);
    B[1][0] = sumatorio(z, tiemposReales, 1, 1);

    std::cout << "B= " << B[0][0] << ", " << B[1][0] << std::endl;

    resolverSistemaEcuaciones(A, B, n, X);

    for (int i = 0; i < n; i++)
    {
        a.push_back(X[i][0]);
    }
}

void calcularTiemposEstimadosNlogN(const std::vector<double> &numeroElementos, const std::vector<double> &a, std::vector<double> &tiemposEstimados)
{
    for (size_t i = 0; i < numeroElementos.size(); i++)
    {
        tiemposEstimados.push_back(a[0] + a[1] * numeroElementos[i] * log10(numeroElementos[i]));
    }
}

double calcularTiempoEstimadoNlogN(const double &n, std::vector<double> &a)
{
    return a[0] + a[1] * n * log10(n);
}

double sumatorio(const std::vector<double> &n, const std::vector<double> &t, int expN, int expT)
{
    double sumN = 0, sumT = 0, sumNT = 0;
    for (size_t i = 0; i < n.size(); i++)
    {
        sumN = pow(n[i], expN) + sumN;
        sumT = pow(t[i], expT) + sumT;
        sumNT = pow(n[i], expN) * pow(t[i], expT) + sumNT;
    }
    if (expN != 0 && expT != 0)
    {
        return sumNT;
    }
    else if (expN != 0)
    {
        return sumN;
    }
    else
    {
        return sumT;
    }
}

double calcularCoeficienteDeterminacion(const std::vector<double> &tiemposReales, const std::vector<double> &tiemposEstimados)
{
    double mediaR = 0, mediaE = 0, varianzaR = 0, varianzaE = 0;
    for (size_t i = 0; i < tiemposReales.size(); i++)
    {
        mediaR = tiemposReales[i] + mediaR;
        mediaE = tiemposEstimados[i] + mediaE;
    }
    mediaR = mediaR / tiemposReales.size();
    mediaE = mediaE / tiemposReales.size();

    for (size_t i = 0; i < tiemposReales.size(); i++)
    {
        varianzaR = pow(tiemposReales[i] - mediaR, 2) + varianzaR;
        varianzaE = pow(tiemposEstimados[i] - mediaE, 2) + varianzaE;
    }
    varianzaR = varianzaR / tiemposReales.size();
    varianzaE = varianzaE / tiemposReales.size();

    return varianzaE / varianzaR;
}

void ajusteFactorial(const std::vector<double> &n, std::vector<double> &tiemposReales, std::vector<double> &a)
{
    std::vector<std::vector<double>> A;
    std::vector<std::vector<double>> B;
    std::vector<std::vector<double>> X;
    std::vector<double> z;
    double factorial = 1;

    A = std::vector<std::vector<double>>(2, std::vector<double>(2));
    B = std::vector<std::vector<double>>(2, std::vector<double>(1));
    X = std::vector<std::vector<double>>(2, std::vector<double>(1));

    for (size_t i = 0; i < n.size(); i++)
    {
        for (int j = n[i]; j > 0; j--)
        {
            factorial = factorial * j;
        }
        z.push_back(factorial);
    }

    A[0][0] = n.size();
    A[0][1] = sumatorio(z, tiemposReales, 1, 0);
    A[1][0] = A[0][1];
    A[1][1] = sumatorio(z, tiemposReales, 2, 0);
    std::cout << "A= " << A[0][0] << ", " << A[0][1] << ", " << A[1][0] << ", " << A[1][1] << std::endl;

    B[0][0] = sumatorio(z, tiemposReales, 0, 1);
    B[1][0] = sumatorio(z, tiemposReales, 1, 1);

    std::cout << "B= " << B[0][0] << ", " << B[1][0] << std::endl;

    resolverSistemaEcuaciones(A, B, 2, X);

    for (int i = 0; i < 2; i++)
    {
        a.push_back(X[i][0]);
    }
}

void calcularTiemposEstimadosFactorial(const std::vector<double> &n, std::vector<double> &tiemposReales, std::vector<double> &a, std::vector<double> &tiemposEstimados)
{
    double factorial = 1;
    for (size_t i = 0; i < n.size(); i++)
    {
        for (int j = n[i]; j > 0; j--)
        {
            factorial = factorial * j;
        }
        tiemposEstimados.push_back(a[0] + a[1] * factorial);
    }
}

double calcularTiempoEstimadosFactorial(const double &n, std::vector<double> &a)
{
    double factorial = 1;
    for (int j = n; j > 0; j--)
    {
        factorial = factorial * j;
    }
    return a[0] + a[1] * factorial;
}

void calcularMatrices(const std::vector<double> &numeroElementos, const std::vector<double> &tiemposReales, int ordenMatrizSistema, std::vector<std::vector<double>> &matrizCoeficientes, std::vector<std::vector<double>> &matrizTerminosIndependientes)
{
    for (int i = 0; i < ordenMatrizSistema; i++)
    {
        for (int j = 0; j < ordenMatrizSistema; j++)
        {
            matrizCoeficientes[i][j] = sumatorio(numeroElementos, tiemposReales, i + j, 0);
        }
    }

    for (int i = 0; i < ordenMatrizSistema; i++)
    {
        matrizTerminosIndependientes[i][0] = sumatorio(numeroElementos, tiemposReales, i, 1);
    }
}

void ajustePolinomico(const std::vector<double> &n, const std::vector<double> &tiemposReales, std::vector<double> &a)
{
    std::vector<std::vector<double>> A;
    std::vector<std::vector<double>> B;
    std::vector<std::vector<double>> X;

    A = std::vector<std::vector<double>>(3, std::vector<double>(3));
    B = std::vector<std::vector<double>>(3, std::vector<double>(1));
    X = std::vector<std::vector<double>>(3, std::vector<double>(1));

    calcularMatrices(n, tiemposReales, 3, A, B);

    resolverSistemaEcuaciones(A, B, 3, X);

    for (int i = 0; i < 3; i++)
    {
        a.push_back(X[i][0]);
    }
}

void calcularTiemposEstimadosPolinomico(const std::vector<double> &n, std::vector<double> &a, std::vector<double> &tiemposEstimados)
{
    for (size_t i = 0; i < n.size(); i++)
    {
        tiemposEstimados.push_back(a[0] + a[1] * n[i] + a[2] * pow(n[i], 2));
    }
}

double calcularTiempoEstimadoPolinomico(const double &n, const std::vector<double> &a)
{
    return a[0] + a[1] * n + a[2] * pow(n, 2);
}

void ajustePolinomicoDegree3(const std::vector<double> &n, const std::vector<double> &tiemposReales, std::vector<double> &a)
{
    std::vector<std::vector<double>> A;
    std::vector<std::vector<double>> B;
    std::vector<std::vector<double>> X;

    A = std::vector<std::vector<double>>(4, std::vector<double>(4));
    B = std::vector<std::vector<double>>(4, std::vector<double>(1));
    X = std::vector<std::vector<double>>(4, std::vector<double>(1));

    calcularMatrices(n, tiemposReales, 4, A, B);

    resolverSistemaEcuaciones(A, B, 4, X);

    for (int i = 0; i < 4; i++)
    {
        a.push_back(X[i][0]);
    }
}

void calcularTiemposEstimadosPolinomicoDegree3(const std::vector<double> &n, const std::vector<double> &a, std::vector<double> &tiemposEstimados)
{
    for (size_t i = 0; i < n.size(); i++)
    {
        tiemposEstimados.push_back(a[0] + a[1] * n[i] + a[2] * pow(n[i], 2) + a[3] * pow(n[i], 3));
    }
}

double calcularTiempoEstimadoPolinomicoDegree3(const double &n, const std::vector<double> &a)
{
    return a[0] + a[1] * n + a[2] * pow(n, 2) + a[3] * pow(n, 3);
}
