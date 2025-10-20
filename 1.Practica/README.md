# Práctica 1: Análisis Empírico de Algoritmos

## 📚 Descripción General

**Proyecto educativo** que demuestra de forma práctica cómo medir, ajustar y validar empíricamente la eficiencia de algoritmos.

**¿Qué hace?** El programa mide tiempos de ejecución reales de algoritmos, ajusta curvas matemáticas a esos datos, y verifica la calidad del ajuste. Es como hacer un "experimento científico" con código.

**¿Que implementa?** 
- Cómo medir tiempos de ejecución en C++
- Cómo ajustar funciones matemáticas a datos reales
- Cómo verificar si tu modelo matemático es correcto
- Conceptos fundamentales de análisis de complejidad

---

## 🎯 Objetivo Pedagógico

Al completar este proyecto, entenderás:

1. **Medición de tiempos:** Cómo usar `Clock` para medir microsegundos
2. **Vectores y referencias:** Cómo pasar datos eficientemente en C++
3. **Algoritmos:** Implementación de Selección, Quicksort y Determinante
4. **Regresión:** Cómo ajustar polinomios a datos experimentales
5. **Validación:** Cómo calcular R² para verificar la calidad del ajuste
6. **Modularidad:** Cómo organizar código en múltiples archivos

---

## 📋 Requisitos

### Software
- **Compilador C++:** g++ o clang (C++11 o superior)
- **CMake:** Versión 3.10 o superior
- **Sistema operativo:** Linux, macOS o Windows (con WSL)

### Instalación (Ubuntu/Debian)
```bash
sudo apt-get install build-essential cmake
```

### Instalación (macOS)
```bash
brew install cmake
```

---

## 📁 Estructura del Proyecto

```
Practica1/
├── README.md                      # Este archivo
├── Practica1.md                   # Especificación oficial
├── CMakeLists.txt                 # Configuración de compilación
│
├── main.cpp                       # Menú principal (punto de entrada)
├── medio_nivel.cpp/hpp            # Orquestación de cada análisis
├── algoritmos.cpp/hpp             # Implementación de algoritmos
├── tiempos.cpp/hpp                # Medición de tiempos y ajuste de curvas
├── auxiliares.cpp/hpp             # Funciones de soporte
├── sistemaEcuaciones.cpp/hpp      # Resolución de sistemas lineales
│
├── docs/                          # Documentación pedagógica
│   ├── COMO_FUNCIONA_EL_CODIGO.md
│   ├── CONCEPTOS_BASICOS.md
│   └── FLUJO_DE_EJECUCION.md
│
└── build/                         # Directorio de compilación (se crea automáticamente)
    └── Practica1_exec             # Ejecutable final
```

---

## 🔧 Explicación de Archivos

### `main.cpp` - Menú Principal
**Propósito:** Punto de entrada del programa  
**Qué hace:** Muestra un menú y llama a las funciones de medio nivel  
**Concepto:** Separación de responsabilidades - main solo maneja la interfaz

### `medio_nivel.cpp` - Orquestación
**Propósito:** Coordina el flujo de cada análisis  
**Qué hace:** 
1. Solicita parámetros al usuario
2. Llama a funciones de medición de tiempos
3. Llama a funciones de ajuste de curvas
4. Muestra resultados

**Concepto:** Patrón de orquestación - coordina componentes

### `algoritmos.cpp` - Implementación de Algoritmos
**Propósito:** Contiene los algoritmos a analizar  
**Funciones:**
- `ordenacionSeleccion()` - Algoritmo O(n²)
- `ordenacionQuicksort()` - Algoritmo O(n log n)
- `determinanteIterativo()` - Cálculo de determinante O(n³)

**Concepto:** Separación de lógica - algoritmos aislados

### `tiempos.cpp` - Medición y Ajuste
**Propósito:** Mide tiempos y ajusta curvas  
**Funciones principales:**
- `tiemposOrdenacionSeleccion()` - Mide tiempos para selección
- `tiemposOrdenacionQuicksort()` - Mide tiempos para Quicksort
- `tiemposDeterminanteIterativo()` - Mide tiempos para determinante
- `ajustePolinomico()` - Ajusta polinomio de grado 2
- `ajusteNlogN()` - Ajusta función n·log(n)
- `ajustePolinomicoDegree3()` - Ajusta polinomio de grado 3

**Concepto:** Reutilización de código - funciones genéricas

### `auxiliares.cpp` - Funciones de Soporte
**Propósito:** Funciones auxiliares reutilizables  
**Funciones:**
- `rellenarVector()` - Rellena vector con números aleatorios
- `rellenarMatriz()` - Rellena matriz con números aleatorios
- `estaOrdenado()` - Verifica si vector está ordenado
- `datosFinales()` - Guarda resultados en archivo

**Concepto:** Modularidad - código reutilizable

### `sistemaEcuaciones.cpp` - Resolución de Sistemas
**Propósito:** Resuelve sistemas de ecuaciones lineales  
**Función:** `resolverSistemaEcuaciones()` - Usa eliminación de Gauss

**Concepto:** Algoritmo numérico - base del ajuste de curvas

---

## 🚀 Cómo Compilar

### Paso 1: Crear directorio de compilación
```bash
cd Practica1
mkdir -p build
cd build
```

### Paso 2: Generar archivos de compilación
```bash
cmake ..
```

**Salida esperada:**
```
-- Configuring done
-- Generating done
-- Build files have been written to: .../build
```

### Paso 3: Compilar
```bash
make
```

**Salida esperada:**
```
[100%] Built target Practica1_exec
```

### Verificación
```bash
ls -la Practica1_exec
```

---

## ▶️ Cómo Ejecutar

### Desde el directorio build
```bash
./Practica1_exec
```

### Menú Principal
```
=== MENU PRINCIPAL ===
1. Ordenacion por Seleccion
2. Ordenacion Quicksort
3. Determinante Iterativo
0. Salir
Seleccione una opción: 
```

---

## 📊 Cómo Usar Cada Apartado

### Apartado 1: Ordenación por Selección

**Parámetros solicitados:**
- `nMin`: Tamaño mínimo (ej: 1000)
- `nMax`: Tamaño máximo (ej: 5000)
- `inc`: Incremento (ej: 500)
- `repeat`: Repeticiones (ej: 10)

**Valores recomendados para prueba rápida:**
```
nMin = 1000
nMax = 5000
inc = 500
repeat = 10
```

**Qué mide:** Tiempo de ordenar vectores de tamaño n  
**Complejidad esperada:** O(n²)  
**Ecuación:** t(n) = a₀ + a₁·n + a₂·n²

---

### Apartado 2: Ordenación Quicksort

**Parámetros solicitados:** Iguales a Apartado 1

**Valores recomendados:**
```
nMin = 1000
nMax = 5000
inc = 500
repeat = 10
```

**Qué mide:** Tiempo de Quicksort  
**Complejidad esperada:** O(n log n)  
**Ecuación:** t(n) = a₀ + a₁·n·log(n)

---

### Apartado 3: Determinante Iterativo

**Parámetros solicitados:**
- `nMin`: Tamaño mínimo (ej: 2)
- `nMax`: Tamaño máximo (ej: 10)
- `inc`: Incremento (ej: 1)

**Valores recomendados:**
```
nMin = 2
nMax = 10
inc = 1
```

**Qué mide:** Tiempo de calcular determinante  
**Complejidad esperada:** O(n³)  
**Ecuación:** t(n) = a₀ + a₁·n + a₂·n² + a₃·n³

---

## 📁 Archivos de Salida

El programa genera dos archivos en el directorio de ejecución:

### `datosFinales.txt`
Contiene 3 columnas:
```
n_elementos  tiempo_real  tiempo_estimado
1000         3999.3       4687.1
1500         8990.0       8915.4
2000         15987.2      15234.6
...
```

**Uso:** Visualizar con gnuplot (ver sección siguiente)

### `tiemposReales.txt`
Contiene 2 columnas:
```
tiempo_real  n_elementos
3999.3       1000
8990.0       1500
15987.2      2000
...
```

---

## 📈 Visualización con Gnuplot

### Instalación
```bash
sudo apt-get install gnuplot  # Ubuntu/Debian
brew install gnuplot          # macOS
```

### Usar Scripts Automáticos (Recomendado)

Después de ejecutar el programa:

```bash
cd build
gnuplot ../grafica_seleccion.gnuplot    # Para Apartado 1
gnuplot ../grafica_quicksort.gnuplot    # Para Apartado 2
gnuplot ../grafica_determinante.gnuplot # Para Apartado 3
```

**Resultado:** Se crean archivos PNG con las gráficas.

### Visualizar Resultados Manualmente
```bash
gnuplot
gnuplot> plot 'datosFinales.txt' using 1:2 with points title 'Real', \
              'datosFinales.txt' using 1:3 with lines title 'Estimado'
gnuplot> quit
```

### Documentación Completa
Ver `docs/GNUPLOT_TUTORIAL.md` para tutorial detallado.

---

## 📚 Documentación Adicional

### Documentación Pedagógica (en `/docs`)
- **`COMO_FUNCIONA_EL_CODIGO.md`** - Explicación línea por línea del programa
- **`CONCEPTOS_BASICOS.md`** - Conceptos de C++ necesarios (vectores, referencias, const, etc.)
- **`FLUJO_DE_EJECUCION.md`** - Diagrama de flujo completo del programa
- **`GNUPLOT_TUTORIAL.md`** - Tutorial de visualización de resultados

### Especificación Oficial
- **`Practica1.md`** - Especificación oficial completa del proyecto

---

## ✅ Verificación Rápida

Después de compilar, verifica que todo funciona:

```bash
cd build
echo -e "1\n1000\n2000\n500\n5\n0" | ./Practica1_exec
```

Deberías ver:
- Menú principal
- Solicitud de parámetros
- Progreso de medición
- Ecuación ajustada
- Coeficiente de determinación (R²)
- Archivos generados

---

## 🐛 Solución de Problemas

### Error: "cmake: command not found"
```bash
sudo apt-get install cmake
```

### Error: "g++: command not found"
```bash
sudo apt-get install build-essential
```

### Error: "Permission denied"
```bash
chmod +x build/Practica1_exec
```

### El programa se ejecuta muy lentamente
Reduce `nMax` o `repeat` en los parámetros

---

## 🎓 Conceptos Clave

| Concepto | Ubicación | Explicación |
|----------|-----------|-------------|
| Vectores | `auxiliares.cpp` | Contenedores dinámicos |
| Referencias | `tiempos.cpp` | Paso eficiente de parámetros |
| Const | `tiempos.cpp` | Protección de datos |
| Punteros | `sistemaEcuaciones.cpp` | Acceso a memoria |
| Complejidad | `Practica1.md` | Análisis de eficiencia |
| Regresión | `tiempos.cpp` | Ajuste de curvas |

---


---

## 📝 Licencia

Este proyecto es material educativo. Úsalo libremente para aprender.

