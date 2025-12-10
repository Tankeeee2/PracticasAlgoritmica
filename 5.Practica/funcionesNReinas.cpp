#include <vector>
#include <iostream>
#include <limits>
#include <cstdlib>
#include "funcionesNReinas.hpp"

using namespace std;

//Esta función obtiene todas las soluciones al problema de las nReinas usando Backtracking
void nReinasBacktracking(const int n, vector< vector<int>> &soluciones)
{
    vector<int> solucion (n);
    solucion[0] = -1;
    int fila = 0;

    while(fila > -1)
    {
        solucion[fila] = solucion[fila] + 1;
        while(solucion[fila] < n && !lugar(solucion, fila))
            solucion[fila] = solucion[fila] + 1;
        if (solucion[fila] < n)
        {
            if (fila == n - 1)
                soluciones.push_back(solucion);
            else 
            {
                fila = fila + 1;
                solucion[fila] = -1;
            }
        } 
        else
            fila = fila - 1; 
    }
}

//Esta función obtiene una solución al problema de las nReinas usando el método de Las Vegas.
bool nReinasLasVegas(int n, vector<int> &solucion)
{
    // Inicializamos el vector solución con -1
    solucion.assign(n, -1);

    int fila = 0;

    // Intentar colocar reinas fila por fila
    while (fila < n)
    {
        // Vector para guardar las columnas disponibles (válidas) en la fila actual
        vector<int> columnasDisponibles;

        // Probamos todas las columnas de la fila actual
        for (int col = 0; col < n; col++)
        {
            solucion[fila] = col; // Colocamos provisionalmente
            if (lugar(solucion, fila)) // Comprobamos si es válido
            {
                columnasDisponibles.push_back(col);
            }
        }

        // Si no hay columnas disponibles, hemos llegado a un callejón sin salida
        // Como es Las Vegas (no backtracking), fallamos inmediatamente en este intento.
        if (columnasDisponibles.empty())
        {
            return false;
        }

        // --- Elección Probabilística (Las Vegas) ---
        // Elegimos una columna al azar de entre las válidas
        int indiceAleatorio = rand() % columnasDisponibles.size();
        solucion[fila] = columnasDisponibles[indiceAleatorio];

        // Pasamos a la siguiente fila
        fila++;
    }

    return true; // Éxito, se colocaron todas las reinas
}

//OPCIONAL. Esta función obtiene todas las soluciones al problema de las nReinas usando el método Las Vegas.
void nReinasLasVegasTodas(const int n, vector< vector<int>> &soluciones)
{
	//Completar
}

//Función que comprueba si la reina que se va a colocar en la fila indicada por el segundo parámetro, 
//apunta a cualquiera de las reinas ubicadas en filas anteriores.
bool lugar(vector<int> &x, const int fila)
{
    for (int i = 0; i < fila; i++)
    {
        // Verificar conflicto de columna: x[i] == x[fila]
        // Verificar conflicto diagonal: distancia filas == distancia columnas
        if (x[i] == x[fila] || abs(x[i] - x[fila]) == abs(i - fila))
        {
            return false; // Hay conflicto
        }
    }
    return true; // Posición válida seguras
}

//Función que muestra todas las soluciones obtenidas para el problema de las nReinas
void escribirSoluciones(std::vector< std::vector <int> >&soluciones)
{
    cout << endl;
    for (auto solucion: soluciones)
    {
        cout << "[" ;
        for (auto valor: solucion)
            cout << " " << valor;
        cout << " ]" << endl;
    }
    cout << "Número de soluciones: " << soluciones.size() << endl;
}

//Función que muestra una solución para el problema de las nReinas. Se usa en el método de las Vegas.
void escribirSolucion(std::vector<int> &solucion)
{
    cout << endl;
    cout << "[";
    for(auto valor: solucion)
        cout << " " << valor;
    cout << " ]" << endl;
}

