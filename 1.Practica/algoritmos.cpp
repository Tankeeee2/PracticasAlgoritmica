#include "algoritmos.hpp"
#include <vector>
#include <cmath>

void ordenacionSeleccion(std::vector<int> &v)
{
    int min_idx;
    for (size_t i = 0; i < v.size() - 1; i++)
    {
        min_idx = i;
        for (size_t j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[min_idx])
            {
                min_idx = j;
            }
        }
        std::swap(v[min_idx], v[i]);
    }
}

// Función auxiliar para Quicksort
int particion(std::vector<int> &v, int bajo, int alto)
{
    int pivote = v[alto];
    int i = bajo - 1;

    for (int j = bajo; j < alto; j++)
    {
        if (v[j] < pivote)
        {
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[alto]);
    return i + 1;
}

// Función recursiva de Quicksort
void quicksortRecursivo(std::vector<int> &v, int bajo, int alto)
{
    if (bajo < alto)
    {
        int pi = particion(v, bajo, alto);
        quicksortRecursivo(v, bajo, pi - 1);
        quicksortRecursivo(v, pi + 1, alto);
    }
}

void ordenacionQuicksort(std::vector<int> &v)
{
    if (v.size() > 0)
    {
        quicksortRecursivo(v, 0, v.size() - 1);
    }
}

// Determinante iterativo por triangularización
double determinanteIterativo(std::vector<std::vector<double>> &M)
{
    int n = M.size();
    double det = 1.0;

    // Crear una copia para no modificar la matriz original
    std::vector<std::vector<double>> A = M;

    // Triangularización de Gauss
    for (int i = 0; i < n; i++)
    {
        // Buscar el pivote
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
        {
            if (std::abs(A[k][i]) > std::abs(A[maxRow][i]))
            {
                maxRow = k;
            }
        }

        // Si el pivote es cero, el determinante es cero
        if (std::abs(A[maxRow][i]) < 1e-10)
        {
            return 0.0;
        }

        // Si hay intercambio de filas, cambiar el signo del determinante
        if (maxRow != i)
        {
            std::swap(A[i], A[maxRow]);
            det *= -1.0;
        }

        // Multiplicar el determinante por el elemento diagonal
        det *= A[i][i];

        // Eliminación de Gauss
        for (int k = i + 1; k < n; k++)
        {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; j++)
            {
                A[k][j] -= factor * A[i][j];
            }
        }
    }

    return det;
}
