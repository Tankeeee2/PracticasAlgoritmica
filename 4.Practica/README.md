# Práctica 4
Prácticas de Algorítmica. 3º de Grado en Ingeniería Informática. Curso 2025-2026.

## Objetivos
Con esta práctica se pretende que el alumno implemente dos algoritmos de segmentación de series temporales basados en la técnica de la programación dinámica.

## Definiciones
Una serie temporal es una sucesión de observaciones de una variable realizadas a intervalos regulares de tiempo.

Una segmentación de la serie temporal es un subconjunto de puntos (puntos dominantes o de corte) que conforman una representación más simple de la misma, conservando la información más relevante.

Como se puede apreciar en la figura, la serie segmentada es una simplificación de la serie original, con lo que supone una compresión de la misma.

Evidentemente, hay diferencias entre la serie segmentada y la original. Existen dos formas de cuantificar esta diferencia de cara a ver la bondad de la segmentación:
*   **Error máximo (eMax)** : Es la máxima distancia, medida en vertical, entre los puntos puntos de la serie y los segmentos rectos que componen la segmentación. En la figura anterior sería la distancia desde el cuarto punto al segmento que queda por debajo (aproximadamente 1.9).
*   **Suma de los errores al cuadrado (ISE)** : Es la suma de los cuadrados de las distancias en vertical de todos los puntos de la serie a los segmentos que la aproximan.

## Enunciado

### Parte obligatoria (8 puntos)
Se ha de implementar el algoritmo de segmentación basados en programación dinámica. El programa principal contendrá un menú con una opciones, que se corresponderá con una función de medio nivel sin parámetros, de forma similar a las prácticas anteriores.
A su vez, en la función de medio nivel invocará a la función de prototipo:

```c++
void SegmentacionDinamica(SerieTemporal &s, int numeroPuntosSegmentacion)
```

La serie se pasa por referencia porque en la función se marcarán los puntos dominantes de la serie en el atributo `dominantePunto` de la misma.
El ISE global, el error máximo y el punto de error máximo se mostrarán en la función de medio nivel, una vez que se haya llamado a la función de segmentación. También hay que mostrar el tiempo que tarda en segmentar.

### Parte opcional (2 puntos)
Una vez realizado lo anterior, de forma automática, se mostrará por pantalla un gráfico con la serie original y la serie segmentada.

Para ello se suministra la clase `SerieTemporal`, y las clase `Punto` y `Recta`, que son clases auxiliares a la clase `SerieTemporal`.

La clase `SerieTemporal` contiene las siguientes funciones miembro:
*   Constructor de la serie a partir de un fichero de puntos. Crea la serie, carga los puntos desde el fichero y los marca como no dominantes.
*   Observador y modificador para devolver o modificar el número de puntos de la serie.
*   Observador y modificador para devolver o modificar un punto de la serie.
*   Observador y modificador para ver o asignar un punto de la serie como dominante.
*   Método para guardar los puntos de la serie temporal en un fichero.
*   Método para guardar los puntos dominantes de la serie temporal en un fichero.
*   Método para contar los puntos dominantes de la serie temporal.
*   Método para calcular la suma de errores cuadráticos (ISE), el error máximo y su ubicación, de la segmentación realizada.
*   Método para calcular la suma de errores cuadráticos entre dos puntos, suponiendo que estos están unidos mediante un segmento. Esta función se ha cambiado con respecto a las prácticas anteriores, para poder acelerar el cálculo de los errores cuadráticos (ISE).
*   Método para calcular el error máximo entre dos puntos y su ubicación, suponiendo que estos están unidos mediante un segmento.
*   Método para mostrar por pantalla los puntos dominantes obtenidos en la segmentación.

Algunos de estos métodos a su vez, hacen uso de los métodos de las clases `Punto` y `Recta`.

## Comprobación
Se suministran varios archivos con series temporales, con extensión `.txt`.
Dado que para las series que habéis usado anteriormente, los métodos de optimización pueden tardar mucho tiempo, las pruebas las debéis hacer con la serie `BBVA50.txt`, que posee solo 50 puntos. Una vez que funcione ya podéis probar la serie original del BBVA.

### BBVA50.txt con una segmentación de 5 puntos:
*   ISE = 7.27153
*   errorMaximo= 1.01388
*   puntoErrorMaximo = 11
*   puntos óptimos de segmentación: 0, 5, 9, 10, 49.

### BBVA.txt con una segmentación de 62 puntos:
*   ISE = 387.193
*   errorMaximo= 1.71817
*   puntoErrorMaximo = 2562

Fecha de comienzo: 24 de noviembre de 2025.
Fecha máxima de entrega: 3 de diciembre de 2025.