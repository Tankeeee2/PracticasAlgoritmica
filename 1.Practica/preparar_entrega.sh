#!/bin/bash

# === CONFIGURACIÓN ===
# Modifica esta variable con tu apellido y nombre
NOMBRE_BASE="Apellidos"
# =====================

# Nombres de las carpetas y el fichero final
CARPETA_ENTREGA="ENTREGA"
CARPETA_COMPLETA="${CARPETA_ENTREGA}/${NOMBRE_BASE}_Completa"
CARPETA_FUENTES="${CARPETA_ENTREGA}/${NOMBRE_BASE}_Fuentes"
FICHERO_TAR="${NOMBRE_BASE}.tar"

echo "Limpiando cualquier intento anterior..."
rm -rf "$CARPETA_ENTREGA"
rm -f "$FICHERO_TAR"

echo "Paso 1: Creando estructura de directorios..."
mkdir -p "$CARPETA_COMPLETA"
mkdir -p "$CARPETA_FUENTES"
echo "Directorios creados."
echo ""

echo "Paso 2: Copiando ficheros a la carpeta '${NOMBRE_BASE}_Completa'..."
# Copia todos los fuentes, cmake y los gráficos
cp *.cpp *.hpp CMakeLists.txt *.eps "$CARPETA_COMPLETA/"
echo "Ficheros para la entrega completa, copiados."
echo ""

echo "Paso 3: Copiando ficheros a la carpeta '${NOMBRE_BASE}_Fuentes'..."
# Copia solo los ficheros del alumno
cp algoritmos.cpp algoritmos.hpp auxiliares.cpp auxiliares.hpp main.cpp medio_nivel.cpp medio_nivel.hpp tiempos.cpp tiempos.hpp "$CARPETA_FUENTES/"
echo "Ficheros fuente del alumno, copiados."
echo ""

echo "Paso 4: Creando el fichero final '${FICHERO_TAR}'..."
# Crea el .tar desde el directorio ENTREGA para que la estructura sea correcta
tar -cvf "$FICHERO_TAR" -C "$CARPETA_ENTREGA" .
echo ""

echo "¡Proceso completado!"
echo "El fichero listo para entregar es: ${FICHERO_TAR}"
