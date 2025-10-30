#include <iostream>
#include <fstream>
#include <chrono>
#include "matriz.hpp"

using namespace std;
using namespace std::chrono;

void mostrarMenu() {
    cout << "\n=== MEDICIÓN DE ALGORITMOS DE EXPONENCIACIÓN DE MATRICES ===" << endl;
    cout << "1. Exponenciación (algoritmo básico)" << endl;
    cout << "2. ExponenciaciónDyV (algoritmo recursivo)" << endl;
    cout << "3. ExponenciaciónDyV Iterativo (algoritmo iterativo)" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void MetodoPotencial() {
    cout << "\n--- Medición Exponenciación (algoritmo básico) ---" << endl;
    
    int opcion;
    cout << "\n1. Usar datos predefinidos (n=20-100, exponente=n)";
    cout << "\n2. Ingresar parámetros manualmente";
    cout << "\nSeleccione una opción: ";
    cin >> opcion;
    
    unsigned int tamano, exponente;
    
    if (opcion == 1) {
        // Modo automático
        ofstream archivo("datosPotencia.txt"); // Sobrescribir archivo existente
        archivo.close();
        
        for (tamano = 20; tamano <= 100; tamano++) {
            exponente = tamano;
            // Código existente para ejecutar la potencia
            ofstream archivo("datosPotencia.txt", ios::app);
            Matriz m(tamano, tamano);
            m.rellenarMatrizAleatoria();
            auto inicio = high_resolution_clock::now();
            Matriz resultado = m.potencia(exponente);
            auto fin = high_resolution_clock::now();
            auto duracion = duration_cast<microseconds>(fin - inicio);
            if (archivo.is_open()) {
                archivo << tamano << " " << duracion.count() / 1000.0 << endl;
                archivo.close();
            }
            cout << "Tamaño: " << tamano << "x" << tamano << " - Tiempo: " 
                 << duracion.count() / 1000.0 << " ms" << endl;
        }
        cout << "\nPrueba completada. Resultados guardados en datosPotencia.txt" << endl;
        return;
    } else {
        // Modo manual
        cout << "\nIngrese el tamaño de la matriz (n x n): ";
        cin >> tamano;
        cout << "Ingrese el exponente: ";
        cin >> exponente;
    }
    
    // Abrir archivo para guardar resultados
    ofstream archivo("datosPotencia.txt", ios::app);
    
    // Crear y rellenar matriz
    Matriz m(tamano, tamano);
    m.rellenarMatrizAleatoria();
    
    // Medir tiempo
    auto inicio = high_resolution_clock::now();
    Matriz resultado = m.potencia(exponente);
    auto fin = high_resolution_clock::now();
    
    auto duracion = duration_cast<microseconds>(fin - inicio);
    
    // Guardar resultado en el archivo
    if (archivo.is_open()) {
        archivo << tamano << " " << duracion.count() / 1000.0 << endl;
        archivo.close();
    }
    
    cout << "Tiempo de ejecución: " << duracion.count() << " microsegundos" << endl;
    cout << "Tiempo de ejecución: " << duracion.count() / 1000.0 << " milisegundos" << endl;
}

void MetodoDyV1() {
    cout << "\n--- Medición ExponenciaciónDyV (algoritmo recursivo) ---" << endl;
    
    int opcion;
    cout << "\n1. Usar datos predefinidos (n=20-100, exponente=n)";
    cout << "\n2. Ingresar parámetros manualmente";
    cout << "\nSeleccione una opción: ";
    cin >> opcion;
    
    unsigned int tamano, exponente;
    
    if (opcion == 1) {
        // Modo automático
        ofstream archivo("datospotenciaDyV1.txt"); // Sobrescribir archivo existente
        archivo.close();
        
        for (tamano = 20; tamano <= 100; tamano++) {
            exponente = tamano;
            // Código existente para ejecutar DyV1
            ofstream archivo("datospotenciaDyV1.txt", ios::app);
            Matriz m(tamano, tamano);
            m.rellenarMatrizAleatoria();
            auto inicio = high_resolution_clock::now();
            Matriz resultado = m.potenciaDyV1(exponente);
            auto fin = high_resolution_clock::now();
            auto duracion = duration_cast<microseconds>(fin - inicio);
            if (archivo.is_open()) {
                archivo << tamano << " " << duracion.count() / 1000.0 << endl;
                archivo.close();
            }
            cout << "Tamaño: " << tamano << "x" << tamano << " - Tiempo: " 
                 << duracion.count() / 1000.0 << " ms" << endl;
        }
        cout << "\nPrueba completada. Resultados guardados en datospotenciaDyV1.txt" << endl;
        return;
    } else {
        // Modo manual
        cout << "\nIngrese el tamaño de la matriz (n x n): ";
        cin >> tamano;
        cout << "Ingrese el exponente: ";
        cin >> exponente;
    }
    
    // Abrir archivo para guardar resultados
    ofstream archivo("datospotenciaDyV1.txt");
    
    // Crear y rellenar matriz
    Matriz m(tamano, tamano);
    m.rellenarMatrizAleatoria();
    
    // Medir tiempo
    auto inicio = high_resolution_clock::now();
    Matriz resultado = m.potenciaDyV1(exponente);
    auto fin = high_resolution_clock::now();
    
    auto duracion = duration_cast<microseconds>(fin - inicio);
    
    // Guardar resultado en el archivo
    if (archivo.is_open()) {
        archivo << tamano << " " << duracion.count() / 1000.0 << endl;
        archivo.close();
    }
    
    cout << "Tiempo de ejecución: " << duracion.count() << " microsegundos" << endl;
    cout << "Tiempo de ejecución: " << duracion.count() / 1000.0 << " milisegundos" << endl;
}

void MetodoDyV2() {
    cout << "\n--- Medición ExponenciaciónDyV Iterativo (algoritmo iterativo) ---" << endl;
    
    int opcion;
    cout << "\n1. Usar datos predefinidos (n=20-100, exponente=n)";
    cout << "\n2. Ingresar parámetros manualmente";
    cout << "\nSeleccione una opción: ";
    cin >> opcion;
    
    unsigned int tamano, exponente;
    
    if (opcion == 1) {
        // Modo automático
        ofstream archivo("datospotenciaDyV2.txt"); // Sobrescribir archivo existente
        archivo.close();
        
        for (tamano = 20; tamano <= 100; tamano++) {
            exponente = tamano;
            // Código existente para ejecutar DyV2
            ofstream archivo("datospotenciaDyV2.txt", ios::app);
            Matriz m(tamano, tamano);
            m.rellenarMatrizAleatoria();
            auto inicio = high_resolution_clock::now();
            Matriz resultado = m.potenciaDyV2(exponente);
            auto fin = high_resolution_clock::now();
            auto duracion = duration_cast<microseconds>(fin - inicio);
            if (archivo.is_open()) {
                archivo << tamano << " " << duracion.count() / 1000.0 << endl;
                archivo.close();
            }
            cout << "Tamaño: " << tamano << "x" << tamano << " - Tiempo: " 
                 << duracion.count() / 1000.0 << " ms" << endl;
        }
        cout << "\nPrueba completada. Resultados guardados en datospotenciaDyV2.txt" << endl;
        return;
    } else {
        // Modo manual
        cout << "\nIngrese el tamaño de la matriz (n x n): ";
        cin >> tamano;
        cout << "Ingrese el exponente: ";
        cin >> exponente;
    }
    
    // Abrir archivo para guardar resultados
    ofstream archivo("datospotenciaDyV2.txt", ios::app);
    
    // Crear y rellenar matriz
    Matriz m(tamano, tamano);
    m.rellenarMatrizAleatoria();
    
    // Medir tiempo
    auto inicio = high_resolution_clock::now();
    Matriz resultado = m.potenciaDyV2(exponente);
    auto fin = high_resolution_clock::now();
    
    auto duracion = duration_cast<microseconds>(fin - inicio);
    
    // Guardar resultado en el archivo
    if (archivo.is_open()) {
        archivo << tamano << " " << duracion.count() / 1000.0 << endl;
        archivo.close();
    }
    
    cout << "Tiempo de ejecución: " << duracion.count() << " microsegundos" << endl;
    cout << "Tiempo de ejecución: " << duracion.count() / 1000.0 << " milisegundos" << endl;
}

int main() {
    srand(time(NULL));
    
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                MetodoPotencial();
                break;
            case 2:
                MetodoDyV1();
                break;
            case 3:
                MetodoDyV2();
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
        
    } while(opcion != 0);
    
    return 0;
}
