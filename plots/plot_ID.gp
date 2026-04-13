set datafile separator ","

# Configuración del gráfico
set title "Distribución de IDs de Deportistas"
set xlabel "Posición"
set ylabel "ID del Deportista"
set grid on
set style data points
set pointsize 1.5

# Salida
set terminal png size 1024,600
set output "plot_ID.png"

# Plotear: columna 1 (ID) vs índice
plot "../db/deportistas700.csv" using 0:1 with points title "ID de Deportistas" linetype 1 linecolor rgb "blue"
