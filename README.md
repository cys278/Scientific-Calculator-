# Scientific Calculator

A feature-rich **Scientific Calculator** implemented in C++ that supports basic arithmetic, advanced mathematical operations, trigonometric functions, equation solving, matrix operations, and more.

---

## Features

### 1. **Basic Arithmetic**
   - Addition
   - Subtraction
   - Multiplication
   - Division (with error handling for division by zero)

### 2. **Advanced Mathematical Operations**
   - Factorial (`n!`)
   - Permutations (`nPr`)
   - Combinations (`nCr`)
   - Arbitrary exponents (`n^r`)
   - Square root, cube root, nth root

### 3. **Trigonometric and Hyperbolic Functions**
   - `sin`, `cos`, `tan` (with degree/radian support)
   - Reciprocal functions: `cosec`, `sec`, `cot`
   - Hyperbolic functions: `sinh`, `cosh`, `tanh`, and their reciprocals

### 4. **Equation Solving**
   - Linear equations
   - Quadratic equations
   - Cubic equations

### 5. **Matrix Operations**
   - Determinant
   - Inversion
   - Addition
   - Subtraction
   - Multiplication

### 6. **Unit Conversions**
   - Degrees ↔ Radians ↔ Gradians
   - Inches ↔ Centimeters
   - Feet ↔ Meters
   - Miles ↔ Kilometers

### 7. **Expression Evaluation**
   - Evaluates arithmetic expressions with proper operator precedence.

---

## Installation

### Prerequisites
- A C++ compiler that supports C++11 or later (e.g., GCC, Clang, or MSVC).

### Compilation
Use the following command to compile the project:
```bash
g++ -o calculator main.cpp calculator.cpp
project/
├── calculator.h      # Header file with class declarations
├── calculator.cpp    # Implementation file
├── testFile.cpp          # Main file for testing the calculator
