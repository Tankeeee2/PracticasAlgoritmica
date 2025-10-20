#!/bin/bash

# Comprueba que se proporcionan dos argumentos
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Uso: $0 <fichero_de_datos> <nombre_del_algoritmo>"
    echo "Ejemplo: $0 datosFinales.txt OrdenacionQuickSort"
    exit 1
fi

inputFile=$1
nombre=$2

if [ -e "$inputFile" ]; then
    cat << end | gnuplot
    set terminal postscript eps color
    set output "$nombre.eps"
    set key right bottom
    set xlabel "N "
    set ylabel "Tiempo en microsegundos"
    plot '$inputFile' using 1:2 t "Tiempos Reales", \
         '$inputFile' using 1:3 t "Tiempos Estimados" w l
end
    echo "Generada la gráfica $nombre.eps a partir de $inputFile"
else
    echo "Error: No se encontró el fichero de entrada '$inputFile'"
fi