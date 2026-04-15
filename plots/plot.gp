#!/usr/bin/env gnuplot

# Configuración general
set terminal pngcairo size 1200,800
set grid
set style data linespoints
set pointsize 1.5
set datafile separator ','

# ============================================
# GRÁFICO 1: ALGORITMOS DE ORDENAMIENTO
# ============================================
set output 'db/resultados/grafico_ordenamiento.png'
set title 'Comparativa de Algoritmos de Ordenamiento (Tiempo Promedio)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
unset logscale y

set style line 1 lc rgb '#e74c3c' lw 2 pt 6  # Bubble Sort - Rojo
set style line 2 lc rgb '#3498db' lw 2 pt 4  # Insertion Sort - Azul
set style line 3 lc rgb '#2ecc71' lw 2 pt 8  # Cocktail Sort - Verde
set style line 4 lc rgb '#f39c12' lw 2 pt 10 # Selection Sort - Naranja

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:4 with linespoints title 'Bubble Sort (promedio)' ls 1, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:7 with linespoints title 'Insertion Sort (promedio)' ls 2, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:13 with linespoints title 'Cocktail Sort (promedio)' ls 3, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:10 with linespoints title 'Selection Sort (promedio)' ls 4

# ============================================
# GRÁFICO 2: COMPARATIVA BUBBLE SORT
# ============================================
set output 'db/resultados/grafico_bubble_sort.png'
set title 'Análisis Bubble Sort (Mejor, Peor, Promedio)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
unset logscale y

set style line 1 lc rgb '#27ae60' lw 2 pt 6  # Mejor - Verde oscuro
set style line 2 lc rgb '#e74c3c' lw 2 pt 4  # Peor - Rojo
set style line 3 lc rgb '#f39c12' lw 2 pt 8  # Promedio - Naranja

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:2 with linespoints title 'Mejor caso' ls 1, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:3 with linespoints title 'Peor caso' ls 2, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:4 with linespoints title 'Caso promedio' ls 3

# GRAFICO 2B: BUBBLE SORT (MEJOR CASO)
set output 'db/resultados/grafico_bubble_sort(mejor caso).png'
set title 'Bubble sort (Mejor caso)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
set logscale y

set style line 1 lc rgb '#27ae60' lw 2 pt 6  # Mejor - Verde oscuro
plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:2 with linespoints title 'Mejor caso' ls 1, \

# ============================================
# GRÁFICO 3: COMPARATIVA INSERTION SORT
# ============================================
set output 'db/resultados/grafico_insertion_sort.png'
set title 'Análisis Insertion Sort (Mejor, Peor, Promedio)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
unset logscale y

set style line 1 lc rgb '#27ae60' lw 2 pt 6  # Mejor - Verde oscuro
set style line 2 lc rgb '#e74c3c' lw 2 pt 4  # Peor - Rojo
set style line 3 lc rgb '#f39c12' lw 2 pt 8  # Promedio - Naranja

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:5 with linespoints title 'Mejor caso' ls 1, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:6 with linespoints title 'Peor caso' ls 2, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:7 with linespoints title 'Caso promedio' ls 3

# GRAFICO 3B: INSERTION SORT (MEJOR CASO)
set output 'db/resultados/grafico_insertion_sort(mejor caso).png'
set title 'Análisis Insertion Sort (mejor caso)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
set logscale y

set style line 1 lc rgb '#27ae60' lw 2 pt 6  # Mejor - Verde oscuro

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:5 with linespoints title 'Mejor caso' ls 1, \


# ============================================
# GRÁFICO 4: COMPARATIVA SELECTION SORT
# ============================================
set output 'db/resultados/grafico_selection_sort.png'
set title 'Análisis Selection Sort (Mejor, Peor, Promedio)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
set logscale y

set style line 1 lc rgb '#27ae60' lw 2 pt 6  # Mejor - Verde oscuro
set style line 2 lc rgb '#e74c3c' lw 2 pt 4  # Peor - Rojo
set style line 3 lc rgb '#f39c12' lw 2 pt 8  # Promedio - Naranja

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:8 with linespoints title 'Mejor caso' ls 1, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:9 with linespoints title 'Peor caso' ls 2, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:10 with linespoints title 'Caso promedio' ls 3

# ============================================
# GRÁFICO 5: COMPARATIVA COCKTAIL SORT
# ============================================
set output 'db/resultados/grafico_cocktail_sort.png'
set title 'Análisis Cocktail Sort (Mejor, Peor, Promedio)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
unset logscale y

set style line 1 lc rgb '#27ae60' lw 2 pt 6  # Mejor - Verde oscuro
set style line 2 lc rgb '#e74c3c' lw 2 pt 4  # Peor - Rojo
set style line 3 lc rgb '#f39c12' lw 2 pt 8  # Promedio - Naranja

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:11 with linespoints title 'Mejor caso' ls 1, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:12 with linespoints title 'Peor caso' ls 2, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:13 with linespoints title 'Caso promedio' ls 3

# GRAFICO 5B: COCKTAIL SORT (MEJOR CASO)
set output 'db/resultados/grafico_cocktail_sort(mejor caso).png'
set title 'Análisis Cocktail Sort (mejor caso)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
set logscale y

set style line 1 lc rgb '#27ae60' lw 2 pt 6  # Mejor - Verde oscuro

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:11 with linespoints title 'Mejor caso' ls 1, \

# ============================================
# GRÁFICO 6: ALGORITMOS DE BÚSQUEDA
# ============================================
set output 'db/resultados/grafico_busqueda.png'
set title 'Comparativa de Algoritmos de Búsqueda (Peor Caso)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
set logscale y

set style line 1 lc rgb '#8e44ad' lw 2 pt 6  # Búsqueda binaria - Púrpura
set style line 2 lc rgb '#16a085' lw 2 pt 4  # Búsqueda secuencial - Teal

plot 'db/resultados/comparativa_busqueda.csv' every ::1 using 1:2 with linespoints title 'Búsqueda Binaria' ls 1, \
     'db/resultados/comparativa_busqueda.csv' every ::1 using 1:3 with linespoints title 'Búsqueda Secuencial' ls 2

# ============================================
# GRÁFICO 7: BÚSQUEDA BINARIA (DETALLE)
# ============================================
set output 'db/resultados/grafico_busqueda_binaria.png'
set title 'Análisis Búsqueda Binaria (Peor Caso)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top right font ',10'
set logscale y

set style line 1 lc rgb '#8e44ad' lw 2 pt 6

plot 'db/resultados/comparativa_busqueda.csv' every ::1 using 1:2 with linespoints title 'Búsqueda Binaria (peor caso)' ls 1

# ============================================
# GRÁFICO 8: BÚSQUEDA SECUENCIAL (DETALLE)
# ============================================
set output 'db/resultados/grafico_busqueda_secuencial.png'
set title 'Análisis Búsqueda Secuencial (Peor Caso)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top right font ',10'
set logscale y

set style line 1 lc rgb '#16a085' lw 2 pt 6

plot 'db/resultados/comparativa_busqueda.csv' every ::1 using 1:3 with linespoints title 'Búsqueda Secuencial (peor caso)' ls 1

print "¡Gráficos generados exitosamente!"
print "Los siguientes archivos PNG han sido creados en db/resultados/:"
print "  - grafico_ordenamiento.png"
print "  - grafico_bubble_sort.png"
print "  - grafico_insertion_sort.png"
print "  - grafico_selection_sort.png"
print "  - grafico_cocktail_sort.png"
print "  - grafico_busqueda.png"
print "  - grafico_busqueda_binaria.png"
print "  - grafico_busqueda_secuencial.png"

