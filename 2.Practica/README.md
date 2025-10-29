# Prácticas de Algorítmica.
## 3º de Grado en Ingeniería Informática.
### Curso 2025-2026.
#### Práctica 2

**Objetivos.**
Con esta práctica se pretende que el alumno implemente un algoritmo basado en la técnica divide y vencerás. En este caso, tendrá que implementar las tres variantes del algoritmo de la exponenciación aplicado al producto de matrices y medir los tiempos correspondientes a las 3 variantes para poder representarlos gráficamente y hacer una comparación del tiempo empleado por las tres variantes.

**Enunciado:**
Implementad el algoritmo de la exponenciación, en las tres variantes explicadas en clase para obtener la potencia de una matriz. Tened en cuenta los siguientes consideraciones:

* En el programa principal habrá un menú con tres (cuatro opciones en el caso de que se haga la opcional) para los tres algoritmos de exponenciación. En cada opción se generará un archivo que contenga el valor de n (orden de la matriz o exponente) y el tiempo empleado por el algoritmo.
* Hay que usar la clase Matriz.
* En el archivo matriz.hpp tenéis las funciones que hay completar de dicha clase y otras que ya están completas.
* Para hacer las pruebas y medir los tiempos, se fijará con un mismo valor el exponente y el orden de la matriz, y se harán variar entre un valor mínimo y un valor máximo, con un incremento (al igual que en la práctica 1). De esta forma se irán obteniendo los tiempos para los distintos valores del exponente de la matriz, y para el mismo valor del exponente, en los tres algoritmos implementados. Probad por ejemplo valor mínimo 20 y valor máximo 100, de esta forma se calculará una matriz de 20x20 elevada a 20, una de 21x21 elevada a 21, una de 22x22 elevada a 22, ……. hasta llegar a una de 100x100 elevada a 100.
* Finalmente, representad gráficamente los valores de tiempos en los tres algoritmos, en función del orden de la matriz (que es igual al exponente).

**Puntuación máxima = 8.**

**Parte adicional:**
Cuando una matriz es diagonalizable (determinante distinto de 0), se puede obtener la potencia enésima diagonalizando la matriz y obteniendo sus autovectores. De esta forma la matriz se puede expresar como A = P*D*P-¹, siendo D la matriz diagonal y P la matriz de paso formada por los autovectores. Se puede demostrar fácilmente que Aⁿ = P*Dⁿ*P⁻¹. Ver ejemplo en: https://fernandorevilla.es/2014/06/13/potencia-enesima-de-una-matriz-por-diagonalizacion/

Añadir a la parte anterior, la implementación del cálculo de la potencia de una matriz usando la matriz diagonal. Para diagonalizarla y para obtener autovectores, se puede adaptar el código suministrado en https://joseguerreroa.wordpress.com/2011/10/04/autovalores-y-autovectores-en-clase-matriz-con-plantillas-template-cc/

Este código solo funciona con matrices simétricas.
Los alumnos que estén interesados en hacer esta parte de la práctica, se pondrán en contacto con el profesor para que les suministre el material necesario.

**Puntuación máxima: 2**

**Fecha de comienzo:** 20 de octubre de 2025.
**Fecha máxima de entrega:** 31 de octubre de 2025.
