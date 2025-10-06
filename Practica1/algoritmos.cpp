#include "algoritmos.hpp"
#include <vector>
#include <cmath>

double algrecursivo(std::vector<std::vector<double>> &M, int b)
{
    double det = 0;
    if (b == 1)
    {
        return M[0][0];
    }
    else if (b > 1)
    {
        for (int k = 1; k < b; k++)
        {
            det = pow(-1, 1 + k) * M[0][k] * algrecursivo(M, k);
        }
    }
    return det;
}

void algoritmoOrdenacionSeleccion(std::vector<int> &v)
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
