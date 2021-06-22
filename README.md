# Sudoku-Generator-Checker-Solver
A Sudoku puzzle generator, checker and solver written in C using backtracking algorithm.

Use terminal as menu for input and output.

![screen](demo.gif)

---

## How to use it
### Running from source code
Tested with GCC in Windows Cmd, Windows Powershell and Bash

```
# Clone project
git clone https://github.com/JavideSs/Sudoku-Generator-Checker-Solver.git
cd Sudoku-Generator-Checker-Solver

# Build with make
make    //make clean to remove binaries

# Build without make
gcc src/main.c lib/control.c lib/functions.c lib/interface.c -o bin/sudoku

# Run sudoku
./bin/sudoku
```
---

## Feedback
Your feedback is most welcomed by filling a
[new issue](https://github.com/JavideSs/Sudoku-Generator-Checker-Solver/issues/new).

---

Author:  
Javier Mellado Sánchez  
2021