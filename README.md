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

## Usage

1. **Interactive Mode** (calculate.cpp):
   ```bash
   ./calculate
   # Enter four numbers: 2 7 8 8
   # Output: (8*(7-(8/2))) = 24#
   ```
   
2. **Validation Mode** (examine.cpp):
   ```bash
   ./examine
   # Checks all test cases in 24.in against 24.ans
   ```
