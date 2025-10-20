# Prácticas de Algorítmica  
### 3º de Grado en Ingeniería Informática  
**Curso 2025-2026**

---

## Práctica 1

### Objetivos
Con esta práctica se pretende que el alumno se familiarice con el cálculo de tiempos de ejecución de un determinado algoritmo en función del tamaño del ejemplar y hacer una estimación empírica de esos tiempos, en función de dicho tamaño.  

Para ello, el alumno deberá implementar un programa en C++ donde se calculen los tiempos de ejecución de varios algoritmos para distintos tamaños del ejemplar y posteriormente se estime, utilizando un enfoque híbrido, la complejidad temporal de esos algoritmos, obteniendo la función de tiempo en función del tamaño del ejemplar.  

El programa resultante tendrá un menú con tres apartados. Cada apartado se invocará en la correspondiente opción del menú mediante una función de medio nivel que no tendrá ningún parámetro.  

Los prototipos de dichas funciones serán:

```cpp
void ordenacionSeleccion();
void ordenacionQuicksort();
void determinanteIterativo();
```

El programa principal tendrá un menú que contendrá solo las llamadas a estas funciones.

---

## Apartado 1 (2.5 puntos)
### Implementación del método de ordenación por selección
Se tendrán en cuenta las siguientes consideraciones:

1. El vector será de elementos de tipo entero y se rellenará aleatoriamente con valores entre 0 y 9999999.  
   ```cpp
   void rellenarVector(vector<int> &v);
   ```

2. Función de ordenación:  
   ```cpp
   void ordenacionSeleccion(vector<int> &v);
   ```

3. En la función de medio nivel `ordenacionSeleccion()` se declararán todas las variables que se usarán como parámetros en las funciones que se invocan desde ella.

4. Función para calcular tiempos reales:  
   ```cpp
   void tiemposOrdenacionSeleccion(int nMin, int nMax, int incremento, int repeticiones, 
                                   vector<double> &tiemposReales, 
                                   vector<double> &numeroElementos);
   ```

   Ejemplo:  
   - mínimo = 1000, máximo = 5000, incremento = 100, repeticiones = 5  
   - se generan 5 vectores de 1000 elementos, se calculan tiempos y se obtiene la media.  
   - se repite hasta 5000, rellenando `tiemposReales` y `numeroElementos`.

5. Ajuste polinómico:  
   ```cpp
   void ajustePolinomico(const vector<double> &numeroElementos, 
                         const vector<double> &tiemposReales, 
                         vector<double> &a);
   ```

   - Ajusta polinomio de grado 2: `t(n) = a0 + a1*n + a2*n²`
   - Se resuelve sistema de ecuaciones con:  
     ```cpp
     void calcularMatrices(const vector<double> &numeroElementos, 
                           const vector<double> &tiemposReales, 
                           int ordenMatrizSistema,
                           vector<vector<double>> &matrizCoeficientes, 
                           vector<vector<double>> &matrizTerminosIndependientes);
     ```

   - Se usarán funciones auxiliares como:  
     ```cpp
     double sumatorio(vector<double> &n, vector<double> &t, int expN, int expT);
     ```

   - Resolver sistema:  
     ```cpp
     void resolverSistemaEcuaciones(vector<vector<double>> matrizCoeficientes, 
                                    vector<vector<double>> matrizTerminosIndependientes, 
                                    int ordenMatrizSistema, 
                                    vector<vector<double>> &X);
     ```

6. Calcular tiempos estimados:  
   ```cpp
   void calcularTiemposEstimadosPolinomico(const vector<double> &numeroElementos, 
                                           const vector<double> &a, 
                                           vector<double> &tiemposEstimados);
   ```

   - Para valores puntuales:  
     ```cpp
     double calcularTiempoEstimadoPolinomico(const double &n, vector<double> &a);
     ```

7. Calcular coeficiente de determinación:  
   ```cpp
   double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, 
                                           const vector<double> &tiemposEstimados);
   ```

8. Guardar resultados en `datosFinales.txt` (3 columnas: número de elementos, tiempos reales, tiempos estimados).  

9. Mostrar al usuario la ecuación ajustada, coeficiente de determinación, y posibilidad de calcular tiempo para cualquier `n`.  

---

## Apartado 2 (3 puntos)
### Implementación del método de ordenación Quicksort
- Pasos 1–4 iguales al apartado anterior.  
- Ajuste `n log n`:  
  ```cpp
  void ajusteNlogN(const vector<double> &numeroElementos, 
                   const vector<double> &tiemposReales, 
                   vector<double> &a);
  ```

  Curva: `t(n) = a0 + a1*n*log(n)`  
  Cambio de variable: `z = n*log(n)`  

- Calcular tiempos estimados:  
  ```cpp
  void calcularTiemposEstimadosNlogN(const vector<double> &numeroElementos, 
                                     const vector<double> &a, 
                                     vector<double> &tiemposEstimados);
  ```

---

## Apartado 3 (2.5 puntos)
### Implementación del cálculo del determinante
- Método de triangularización sobre matrices `double`.  
- Rellenar con valores aleatorios entre **0.95 y 1.05**.  
- Pruebas iguales al apartado 1, con diferencias:  
  1. Para cada `n`, solo una prueba.  
  2. Ajuste polinómico de grado 3.  
  3. Función de tiempos estimados similar a apartado 1.  

---

## Apartado 4 (Opcional, 2 puntos)
- Repetir apartado 1 hasta obtener tiempos reales.  
- Seleccionar aleatoriamente 80% de puntos para curva de ajuste.  
- Con el 20% restante, comprobar coeficiente de determinación.  

---

## Anexo
- Explicación sobre regresión polinómica y ajuste por mínimos cuadrados.  
- Uso de la función:  
  ```cpp
  void resolverSistemaEcuaciones(vector<vector<double>> A, 
                                 vector<vector<double>> B, 
                                 int n, 
                                 vector<vector<double>> &X);
  ```
- Declaración y reserva de matrices con STL:  
  ```cpp
  vector<vector<double>> matrizDatos;
  matrizDatos = vector<vector<double>>(filas, vector<double>(columnas));
  ```

### Ejemplo práctico 1
Ajuste polinómico de grado 2:  
`t(n) = a0 + a1*n + a2*n²`  

Ejemplo de sistema de ecuaciones y resultados, con coeficiente de determinación ≈ **0.992 (99.2%)**

### Ejemplo práctico 2
Ajuste `n log n`:  
`t(n) = a0 + a1*n*log(n)`  

Resultados con coeficiente de determinación ≈ **0.99 (99.0%)**

---

## Fechas
- **Fecha de comienzo:** 15 de septiembre de 2025  
- **Fecha de entrega:** 13 de octubre de 2025  
