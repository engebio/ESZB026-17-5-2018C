#!/bin/sh
ARQUIVODADOS=/home/pi/ESZB026-17-5-2018C/lab07/dados01.txt
ARQUIVOSAIDA=/home/pi/ESZB026-17-5-2018C/lab07/dados01.png

gnuplot << EOF
set title "Gráfico da função 1"
set ylabel "2^x"
set xlabel "x"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
     linecolor rgb '#0073ad' \
     linetype 2 \
     linewidth 3 \
     pointtype 4 \
     pointsize 3.0 \
     title "meus dados" \
     with linespoints
EOF

