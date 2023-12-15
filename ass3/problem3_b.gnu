set terminal png size 500,500
set output "problem1_b_graph.png"

set border linewidth 1.5

set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2
set style line 2 linecolor rgb '#00ff00' linetype 1 linewidth 2

set xrange [0:100]
set yrange [0:900]

set xlabel "n"
set ylabel "function values"

f(x) = 9*x**0.8 + 2*x**0.3 + 14*log(x)
g(x) = sqrt(x)

plot f(x) title 'f(n)' with lines linestyle 1, \
     g(x) title 'g(n)' with lines linestyle 2 \
