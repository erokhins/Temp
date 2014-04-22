rm -f a.out
gcc -w -fopenmp 2.c && echo "Compiled, run:" && ./a.out
