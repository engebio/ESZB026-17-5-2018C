#!/bin/sh
ARQUIVODADOS=/home/pi/ESZB026-17-5-2018C/lab07/dados02.txt
ARQUIVOSAIDA=/home/pi/ESZB026-17-5-2018C/lab07/dados02.png

gnuplot << EOF
set title "Gráfico da função 2"
set ylabel "x^2"
set xlabel "x"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#0098ad' \
     linetype 2 \
     linewidth 1 \
     pointtype 5 \
     pointsize 2.3 \
     title "pontos" \
     with linespoints
EOF

