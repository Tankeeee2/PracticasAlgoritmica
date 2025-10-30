#!/bin/bash

Potencia="Potencia"
PotenciaDyV1="potenciaDyV1"
PotenciaDyV2="potenciaDyV2"

# Verificar que todos los archivos existen
todos_existen=true
for nombre in "$Potencia" "$PotenciaDyV1" "$PotenciaDyV2"
do
    if [ ! -e "datos$nombre.txt" ]
    then
        echo "Error: No se encuentra el archivo datos$nombre.txt"
        todos_existen=false
    fi
done

# Si todos los archivos existen, generar la gráfica combinada
if [ "$todos_existen" = true ]
then
    cat << end | gnuplot
    set terminal postscript eps color
    set output "ComparacionAlgoritmos.eps"
    set key right top
    set xlabel "Tamaño (N)"
    set ylabel "Tiempo (milisegundos)"
    set title "Comparación de Tiempos de Ejecución"
    set grid
    plot 'datos$Potencia.txt' using 1:2 with linespoints lw 2 pt 7 ps 0.8 t "Ordenación Potencia", \
         'datos$PotenciaDyV1.txt' using 1:2 with linespoints lw 2 pt 9 ps 0.8 t "Multiplicación Matrices", \
         'datos$PotenciaDyV2.txt' using 1:2 with linespoints lw 2 pt 5 ps 0.8 t "Determinante Recursivo"
end
    echo "Gráfica generada: ComparacionAlgoritmos.eps"
else
    echo "No se puede generar la gráfica. Faltan archivos."
fi

# Opcionalmente, también generar las gráficas individuales (como en el script original)
for nombre in "$Potencia" "$PotenciaDyV1" "$PotenciaDyV2"
do
    if [ -e "datos$nombre.txt" ]
    then
        cat << end | gnuplot
        set terminal postscript eps color
        set output "$nombre.eps"
        set key right bottom
        set xlabel "Tamaño (N)"
        set ylabel "Tiempo (milisegundos)"
        set title "$nombre"
        plot 'datos$nombre.txt' using 1:2 with linespoints lw 2 t "Tiempos Reales"
end
        echo "Gráfica individual generada: $nombre.eps"
    fi
done