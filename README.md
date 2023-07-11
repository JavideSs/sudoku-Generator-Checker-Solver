# Sudoku-Generator-Checker-Solver
A Sudoku puzzle generator, checker and solver written in C using backtracking algorithm.

Use terminal as menu for input and output.

![screen](demo.gif)

---

## How to use it
Is platform independent, terminal must support ANSI.
makefile developed for Linux.

```
# Clone project
git clone https://github.com/JavideSs/sudoku-Generator-Checker-Solver.git
cd sudoku-generator-checker-solver

# Build with make
make    #make clean to remove binaries

# Build without make
gcc -w -O3 -Iinclude lib/* src/main.c -o bin/sudoku

# Run sudoku
./bin/sudoku
```

---

## Feedback
Your feedback is most welcomed by filling a
[new issue](https://github.com/JavideSs/sudoku-Generator-Checker-Solver/issues/new).

---

Author:  
Javier Mellado Sánchez  
2021-2022