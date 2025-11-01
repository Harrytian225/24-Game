# 24 Game Solver

A C++ program that solves the 24 Game puzzle - given four numbers, find an expression that evaluates to 24 using basic arithmetic operations (+, -, ×, ÷).

## Files Description

### calculate.cpp
- **Input**: Four numbers (1-13 range, or larger). Enter `0` as first number to exit.
- **Output**: 
  - A valid expression that equals 24, OR
  - `"You try it"` if no solution exists.

### examine.cpp  
- **Input**: Reads from `24.in` (test cases) and `24.ans` (proposed answers)
- **Output**:
  - `"all correct!"` if all answers are valid and evaluate to 24
  - Error messages for incorrect solutions

## Compilation

```bash
g++ -std=c++11 -O2 24-Game.cpp -o 24-Game
./24-Game
```

## Usage

1. **Interactive Mode** (calculate.cpp):
   ```bash
   
   example input:
   3 3 8 8
   4 4 6 6 
   4 4 10 10
   3 3 7 7 
   1 2 3 4
   
   example output:
   Case #1: 8/(3-(8/3))
   Case #2: You try it.
   Case #3: ((10*10)-4)/4
   Case #4: ((3/7)+3)*7
   Case #5: ((1+2)+3)*4
   ```
   
2. **Validation Mode** (examine.cpp):
   ```bash
   all correct!
   (My examine.cpp reads inputs from 24.in and 24.ans to judge whether the answer and format is correct, so one can modify the content in 24.in and 24.ans to change the output of my program. )
   ```
