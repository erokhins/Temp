rm -f a.out
gcc -w -fopenmp 5.c && echo "Compiled, run:" && ./a.out
