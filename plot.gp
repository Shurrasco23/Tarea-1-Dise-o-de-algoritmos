#!/usr/bin/env gnuplot

# Configuración general 
set terminal pngcairo size 1200,800
set grid
set style data linespoints
set pointsize 1.5
set datafile separator ','

# ============================================
# DEFINICIÓN DE ESTILOS (COLORES)
# ============================================
# Colores para comparar algoritmos entre sí
set style line 1 lc rgb '#e74c3c' lw 2 pt 6  # Bubble Sort - Rojo 
set style line 2 lc rgb '#3498db' lw 2 pt 4  # Insertion Sort - Azul 
set style line 3 lc rgb '#f39c12' lw 2 pt 10 # Selection Sort - Naranja 
set style line 4 lc rgb '#2ecc71' lw 2 pt 8  # Cocktail Sort - Verde 

# Colores para comparar casos (Mejor, Peor, Promedio)
set style line 10 lc rgb '#27ae60' lw 2 pt 6 # Mejor - Verde oscuro 
set style line 11 lc rgb '#e74c3c' lw 2 pt 4 # Peor - Rojo 
set style line 12 lc rgb '#f39c12' lw 2 pt 8 # Promedio - Naranja 


# ============================================
# PARTE 1: COMPARATIVAS GLOBALES POR CASO
# ============================================

# GRÁFICO 1.1: COMPARATIVA MEJORES CASOS
set output 'db/resultados/grafico_comparativa_mejor.png'
set title 'Comparativa de Algoritmos (Mejores Casos)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
set logscale y

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:2 with linespoints title 'Bubble Sort (Mejor)' ls 1, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:5 with linespoints title 'Insertion Sort (Mejor)' ls 2, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:8 with linespoints title 'Selection Sort (Mejor)' ls 3, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:11 with linespoints title 'Cocktail Sort (Mejor)' ls 4

# GRÁFICO 1.2: COMPARATIVA PEORES CASOS
set output 'db/resultados/grafico_comparativa_peor.png'
set title 'Comparativa de Algoritmos (Peores Casos)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12'
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top left font ',10'
unset logscale y

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:3 with linespoints title 'Bubble Sort (Peor)' ls 1, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:6 with linespoints title 'Insertion Sort (Peor)' ls 2, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:9 with linespoints title 'Selection Sort (Peor)' ls 3, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:12 with linespoints title 'Cocktail Sort (Peor)' ls 4

# GRÁFICO 1.3: COMPARATIVA CASOS PROMEDIO
set output 'db/resultados/grafico_comparativa_promedio.png'
set title 'Comparativa de Algoritmos (Casos Promedio)' font ',16'
set xlabel 'Tamaño de la muestra' font ',12' 
set ylabel 'Tiempo de ejecución (segundos)' font ',12' 
set key top left font ',10' 
unset logscale y 

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:4 with linespoints title 'Bubble Sort (Promedio)' ls 1, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:7 with linespoints title 'Insertion Sort (Promedio)' ls 2, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:10 with linespoints title 'Selection Sort (Promedio)' ls 3, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:13 with linespoints title 'Cocktail Sort (Promedio)' ls 4


# ============================================
# PARTE 2: ANÁLISIS INDIVIDUAL POR ALGORITMO
# ============================================

# GRÁFICO 2.1: BUBBLE SORT (Mejor, Peor, Promedio) 
set output 'db/resultados/grafico_bubble_sort.png' 
set title 'Análisis Bubble Sort (Mejor, Peor, Promedio)' font ',16' 
set xlabel 'Tamaño de la muestra' font ',12' 
set ylabel 'Tiempo de ejecución (segundos)' font ',12' 
set key top left font ',10' 
unset logscale y 

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:2 with linespoints title 'Mejor caso' ls 10, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:3 with linespoints title 'Peor caso' ls 11, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:4 with linespoints title 'Caso promedio' ls 12

# GRÁFICO 2.2: INSERTION SORT (Mejor, Peor, Promedio) 
set output 'db/resultados/grafico_insertion_sort.png' 
set title 'Análisis Insertion Sort (Mejor, Peor, Promedio)' font ',16' 
set xlabel 'Tamaño de la muestra' font ',12' 
set ylabel 'Tiempo de ejecución (segundos)' font ',12' 
set key top left font ',10' 
unset logscale y 

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:5 with linespoints title 'Mejor caso' ls 10, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:6 with linespoints title 'Peor caso' ls 11, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:7 with linespoints title 'Caso promedio' ls 12

# GRÁFICO 2.3: SELECTION SORT (Mejor, Peor, Promedio) 
set output 'db/resultados/grafico_selection_sort.png' 
set title 'Análisis Selection Sort (Mejor, Peor, Promedio)' font ',16' 
set xlabel 'Tamaño de la muestra' font ',12' 
set ylabel 'Tiempo de ejecución (segundos)' font ',12' 
set key top left font ',10' 
unset logscale y # Ajustado a unset para coherencia, cambiar a 'set logscale y' si lo necesitas 

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:8 with linespoints title 'Mejor caso' ls 10, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:9 with linespoints title 'Peor caso' ls 11, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:10 with linespoints title 'Caso promedio' ls 12

# GRÁFICO 2.4: COCKTAIL SORT (Mejor, Peor, Promedio) 
set output 'db/resultados/grafico_cocktail_sort.png' 
set title 'Análisis Cocktail Sort (Mejor, Peor, Promedio)' font ',16' 
set xlabel 'Tamaño de la muestra' font ',12' 
set ylabel 'Tiempo de ejecución (segundos)' font ',12' 
set key top left font ',10' 
unset logscale y 

plot 'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:11 with linespoints title 'Mejor caso' ls 10, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:12 with linespoints title 'Peor caso' ls 11, \
     'db/resultados/comparativa_ordenamiento.csv' every ::1 using 1:13 with linespoints title 'Caso promedio' ls 12


# ============================================
# PARTE 3: ALGORITMOS DE BÚSQUEDA (Mantenido) 
# ============================================
set output 'db/resultados/grafico_busqueda.png' 
set title 'Comparativa de Algoritmos de Búsqueda (Peor Caso)' font ',16' 
set xlabel 'Tamaño de la muestra' font ',12' 
set ylabel 'Tiempo de ejecución (segundos)' font ',12' 
set key top left font ',10' 
set logscale y 

set style line 20 lc rgb '#8e44ad' lw 2 pt 6  # Búsqueda binaria - Púrpura 
set style line 21 lc rgb '#16a085' lw 2 pt 4  # Búsqueda secuencial - Teal 

plot 'db/resultados/comparativa_busqueda.csv' every ::1 using 1:2 with linespoints title 'Búsqueda Binaria' ls 20, \
     'db/resultados/comparativa_busqueda.csv' every ::1 using 1:3 with linespoints title 'Búsqueda Secuencial' ls 21

# BÚSQUEDA BINARIA (DETALLE) 
set output 'db/resultados/grafico_busqueda_binaria.png' 
set title 'Análisis Búsqueda Binaria (Peor Caso)' font ',16' 
set xlabel 'Tamaño de la muestra' font ',12' 
set ylabel 'Tiempo de ejecución (segundos)' font ',12' 
set key top right font ',10' 
set logscale y 

plot 'db/resultados/comparativa_busqueda.csv' every ::1 using 1:2 with linespoints title 'Búsqueda Binaria (peor caso)' ls 20 

# BÚSQUEDA SECUENCIAL (DETALLE) 
set output 'db/resultados/grafico_busqueda_secuencial.png' 
set title 'Análisis Búsqueda Secuencial (Peor Caso)' font ',16' 
set xlabel 'Tamaño de la muestra' font ',12' 
set ylabel 'Tiempo de ejecución (segundos)' font ',12'
set key top right font ',10' 
set logscale y 

plot 'db/resultados/comparativa_busqueda.csv' every ::1 using 1:3 with linespoints title 'Búsqueda Secuencial (peor caso)' ls 21 


# ============================================
# MENSAJE DE FINALIZACIÓN
# ============================================
print "¡Gráficos generados exitosamente!" 
print "Los siguientes archivos PNG han sido creados en db/resultados/:" 
print "  - grafico_comparativa_mejor.png"
print "  - grafico_comparativa_peor.png"
print "  - grafico_comparativa_promedio.png"
print "  - grafico_bubble_sort.png" 
print "  - grafico_insertion_sort.png" 
print "  - grafico_selection_sort.png" 
print "  - grafico_cocktail_sort.png" 
print "  - grafico_busqueda.png" 
print "  - grafico_busqueda_binaria.png" 
print "  - grafico_busqueda_secuencial.png" 