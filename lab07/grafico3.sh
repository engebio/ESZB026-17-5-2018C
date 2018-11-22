#!/bin/sh
ARQUIVODADOS=/home/pi/ESZB026-17-5-2018C/lab07/dados03.txt
ARQUIVOSAIDA=/home/pi/ESZB026-17-5-2018C/lab07/dados03.png

gnuplot << EOF
set title "Gráfico da função 3"
set ylabel "360/x"
set xlabel "x"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#0031ad' \
     linetype 2 \
     linewidth 4 \
     pointtype 6 \
     pointsize 1.8 \
     title "my data" \
     with linespoints
EOF

