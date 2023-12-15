set terminal png size 500,500
set output "problem1_c_graph.png"

set border linewidth 1.5

set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2
set style line 2 linecolor rgb '#00ff00' linetype 1 linewidth 2

set xrange [0:80]
set yrange [0:400]

set xlabel "n"
set ylabel "function values"

log_2(x) = log(x) / log(2)

f(x) = x**2 / (log(x)/log(2))
g(x) = x*(log(x)/log(2))

plot f(x) title 'f(n)' with lines linestyle 1, \
     g(x) title 'g(n)' with lines linestyle 2 \
