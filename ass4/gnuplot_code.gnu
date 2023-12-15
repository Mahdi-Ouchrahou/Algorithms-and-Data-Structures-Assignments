set terminal png size 1500,1500
set output "graph.png"

set xrange [0:900]
set yrange [0:1000]


set border linewidth 1.5

set xlabel 'Values of K'
set ylabel 'Time t'


set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2
set style line 2 linecolor rgb '#00ff00' linetype 1 linewidth 2
set style line 3 linecolor rgb '#A94064' linetype 1 linewidth 2
plot "time.txt" using 1:2 title "Worst Case" with lines linestyle 1, \
     "time.txt" using 1:3 title "Best Case" with lines linestyle 2, \
     "time.txt" using 1:4 title "Average Case" with lines linestyle 3
