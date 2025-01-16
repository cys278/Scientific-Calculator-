#include "calculator.h"
#include <iostream>
#include <cmath>
#include <stack>
#include <sstream>
#include <cctype> // For character-related functions like isdigit()
#include <cstring> //For C-string functions like strcpy(), strtok(), etc.
using namespace std;


Calculator ::Calculator():PI(3.14159265358979323846), E(2.71828182845904523536) {}

//Constants
float Calculator::getPI() const{
    return PI;
}

float Calculator::getEuler() const{
    return E;
}

//Factorial, Permutation and Combination

int Calculator::factorial(const int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int Calculator::permutation(const int n,const int r) {
    if (n >= r) {
        // Calculate permutation using factorial function
        return factorial(n) / factorial(n - r);
    } else {
        // If n is less than r, return 0
        return 0;
    }
}

int Calculator::combination(const int n,const int r) {
    return factorial(n) / factorial(n - r);
}


//General Operations

float Calculator::addition(const vector<float>& v1) {
    float sum = 0;
    for (size_t i=0;i<v1.size();i++) {
        sum += v1[i];
    }
    return sum;
}

float Calculator::subtraction(const vector<float>& v1) {
    if (v1.empty()) {
        cerr << "Error: No numbers provided for subtraction." << endl;
        return 0; // Return 0 if no numbers provided
    }
    float result =v1[0];
    for (size_t i = 1; i < v1.size(); i++) {
        result -= v1[i];
    }
    return result;
}


float Calculator::multiplication(const vector<float>& v1) {
    if (v1.empty()) {
        cerr << "Error: No numbers provided for multiplication." << endl;
        return 0; // Return 0 if no numbers provided
    }
    float product = 1;
    for (size_t i = 1; i < v1.size(); i++) {
        product *= v1[i];
    }
    return product;
}

float Calculator::division(const vector<float>& v1) {
    if (v1.empty()) {
        cerr << "Error: No numbers provided for division." << endl;
        return 0; // Return 0 if no numbers provided
    }
    float result = v1[0];
    for (size_t i = 1; i < v1.size(); i++) {
        if (v1[i] == 0) {
            cerr << "Error: Division by zero." << endl;
            return 0; // Return 0 if division by zero occurs
        }
        result /= v1[i];
    }
    return result;
}

float Calculator::evaluateExpression(const string& expression) {
    stack<float> values;
    stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        if (expression[i] == ' ')
            continue;
        else if (isdigit(expression[i])) {
            float val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                ++i;
            }
            --i;
            values.push(val);
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                float val2 = values.top(); values.pop();
                float val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(val1, val2, op));
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                float val2 = values.top(); values.pop();
                float val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(val1, val2, op));
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        float val2 = values.top(); values.pop();
        float val1 = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(val1, val2, op));
    }

    return values.top();
}

//Equitional Operations

void Calculator::linearEquation(float a1, float a2, float b1, float b2, float c1, float c2) {
    float x, y, a, b, c;
    a = (a1 / a2);
    b = (b1 / b2);
    c = (c1 / c2);
    if (a == b && b != c)
        cout << "No Solution" << endl;
    else if (a == b && b == c)
        cout << "Infinite Solutions" << endl;
    else if (a != b) {
        x = ((b1 * c2) - (b2 * c1)) / ((a1 * b2) - (a2 * b1));
        y = ((a2 * c1) - (a1 * c2)) / ((a1 * b2) - (a2 * b1));
    }
    cout << "The solutions for the equation are: " << x << " and " << y << endl;
}

void Calculator::quadraticSolution(float a, float b, float c) {
    float d, x1, x2;
    d = pow(b, 2) - (4 * a * c);
    x1 = (-b + sqrt(d)) / (2 * a);
    x2 = (-b - sqrt(d)) / (2 * a);
    cout << "The solutions for the quadratic function are: " << x1 << " and " << x2 << endl;
}



void Calculator::cubicEquations(const double& a,const  double& b,const double& c,const double& d)
{
    if (a == 0) {
        cerr << "Error: This is not a cubic equation." << endl;
        return;
    }

    // Normalizing the coefficients
    double normA = b / a;
    double normB = c / a;
    double normC = d / a;

    // Calculate intermediate values
    double Q = (3 * normB - normA * normA) / 9;
    double R = (9 * normA * normB - 27 * normC - 2 * normA * normA * normA) / 54;
    double D = Q * Q * Q + R * R;

    if (D >= 0) {
        // Three real roots
        double S = cbrt(R + sqrt(D));
        double T = cbrt(R - sqrt(D));

        double x1 = -normA / 3 + (S + T);
        double x2 = -normA / 3 - (S + T) / 2;
        double x3 = -normA / 3 - (S + T) / 2;

        cout << "Real roots:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "x3 = " << x3 << endl;
    } else {
        // One real root
        double theta = acos(R / sqrt(-(Q * Q * Q)));
        double x1 = 2 * sqrt(-Q) * std::cos(theta / 3) - normA / 3;

        cout << "One real root:" << endl;
        cout << "x1 = " << x1 << endl;

        // Two complex roots
        cout << "Two complex roots:" << endl;
        cout << "x2 = " << -sqrt(-Q) * (std::cos(theta / 3 ) + sqrt(3) * std::sin(theta / 3)) - normA / 3 << endl;
        cout << "x3 = " << -sqrt(-Q) * (std::cos(theta / 3 ) - sqrt(3) * std::sin(theta / 3)) - normA / 3 << endl;
    }
}


//Conversions

float Calculator::inchesToCentimeters(float inches) {
    return inches * 2.54; // 1 inch = 2.54 centimeters
}

float Calculator::centimetersToInches(float centimeters) {
    return centimeters / 2.54; // 1 centimeter = 0.3937 inches
}

float Calculator::feetToMeters(float feet) {
    return feet * 0.3048; // 1 foot = 0.3048 meters
}

float Calculator::metersToFeet(float meters) {
    return meters / 0.3048; // 1 meter = 3.2808 feet
}

float Calculator::milesToKilometers(float miles) {
    return miles * 1.60934; // 1 mile = 1.60934 kilometers
}

float Calculator::kilometersToMiles(float kilometers) {
    return kilometers / 1.60934; // 1 kilometer = 0.621371 miles
}

float Calculator::degreesToGrads(float degrees) {
    return degrees * 1.11111; // 1 degree = 1.11111 grads
}

float Calculator::gradsToDegrees(float grads) {
    return grads / 1.11111; // 1 grad = 0.9 degrees
}

float Calculator::degreeToRadian(float degrees)  {
        return degrees * (M_PI / 180.0);
}

float Calculator::radianToDegree(float radians){
        return radians * (180.0 / M_PI);
}



//Trigonometric Operations

float Calculator::sin(float x, bool isDegree) {
    if (isDegree)
        x = x * M_PI / 180; 
    return std::sin(x);
}

float Calculator::cos(float x, bool isDegree) {
    if (isDegree)
        x = x * M_PI / 180; 
    return std::cos(x);
}

float Calculator::tan(float x, bool isDegree) {
    if (isDegree)
        x = x * M_PI / 180; 
    return std::tan(x);
}

float Calculator::cosec(float x, bool isDegree) {
    if (isDegree)
        x = x * getPI() / 180; // Convert degrees to radians
    float sinValue = std::sin(x);
    if (sinValue == 0)
        return INFINITY; // for Handlin the case when sin(x) is zero
    else
        return 1 / sinValue;
}

float Calculator::sec(float x, bool isDegree) {
    if (isDegree)
        x = x * M_PI / 180; // Convert degrees to radians
    float cosValue = std::cos(x);
    if (cosValue == 0)
        return INFINITY; // Handle the case when cos(x) is zero
    else
        return 1 / cosValue;
}

float Calculator::cot(float x, bool isDegree) {
    if (isDegree)
        x = x * M_PI / 180; // Convert degrees to radians
    float tanValue = std::tan(x);
    if (tanValue == 0)
        return INFINITY; // Handle the case when tan(x) is zero
    else
        return 1 / tanValue;
}


//Hyperbolic Trigonometric Operations
float Calculator::sinh(float& angle,bool isDegree) {
    if(isDegree)
    angle=angle*M_PI/180;
    return std::sinh(angle);
}

float Calculator::cosh(float& angle,bool isDegree) {
        if(isDegree)
        angle=angle*M_PI/180;
        return std::cosh(angle);
}

float Calculator:: tanh(float& angle,bool isDegree) {
        if(isDegree)
        angle=angle*M_PI/180;
        return std::tanh(angle);
}

float Calculator::cosech(float& angle,bool isDegree){
    if(isDegree)
        angle = degreeToRadian(angle);
    return (std::sinh(angle) == 0) ? INFINITY : (1 / std::sinh(angle));
}

float Calculator::sech(float& angle,bool isDegree){
    if(isDegree)
        angle = degreeToRadian(angle);
    return (std::cosh(angle) == 0)?INFINITY : (1 / std::sinh(angle));
    
    
}

float Calculator::coth(float& angle,bool isDegree)
{
    if(isDegree)
        angle=degreeToRadian(angle);
    return (std::tanh(angle) == 0)?INFINITY : (1 / std::sinh(angle));
}



//Determine Angle 

float Calculator::angle(const float& value, const string& w) {
    float result;
    if (w == "sin") {
        if (value >= -1 && value <= 1) {
            result = std::asin(value);
        } else {
            cerr << "Input value out of range for sin function." << endl;
            result = NAN; // Not-A-Number to indicate an error
        }
    } else if (w == "cos") {
        if (value >= -1 && value <= 1) {
            result = std::acos(value);
        } else {
            cerr << "Input value out of range for cos function." << endl;
            result = NAN; // Not-A-Number to indicate an error
        }
    } else if (w == "tan") {
        result = std::atan(value);
    } else if (w == "cosec") {
        if (value != 0) {
            result = std::asin(1.0 / value);
        } else {
            cerr << "Division by zero error for cosec function." << endl;
            result = NAN; // Not-A-Number to indicate an error
        }
    } else if (w == "sec") {
        if (value != 0) {
            result = std::acos(1.0 / value);
        } else {
            cerr << "Division by zero error for sec function." << endl;
            result = NAN; // Not-A-Number to indicate an error
        }
    } else if (w == "cot") {
        if (value != 0) {
            result = std::atan(1.0 / value);
        } else {
            cerr << "Division by zero error for cot function." << endl;
            result = NAN; // Not-A-Number to indicate an error
        }
    } else if (w == "sinh") {
        result = std::asinh(value);
    } else if (w == "cosh") {
        result = std::acosh(value);
    } else if (w == "tanh") {
        result = std::atanh(value);
    } else if (w == "cosech") {
        if (value != 0) {
            result = std::asinh(1.0 / value);
        } else {
            cerr << "Division by zero error for cosech function." << endl;
            result = NAN; // Not-A-Number to indicate an error
        }
    } else if (w == "sech") {
        if (value != 0) {
            result = std::acosh(1.0 / value);
        } else {
            cerr << "Division by zero error for sech function." << endl;
            result = NAN; // Not-A-Number to indicate an error
        }
    } else if (w == "coth") {
        if (value != 0) {
            result = std::atanh(1.0 / value);
        } else {
            cerr << "Division by zero error for coth function." << endl;
            result = NAN; // Not-A-Number to indicate an error
        }
    } else {
        cerr << "Invalid trigonometric function. Please try again!" << endl;
        result = NAN; // Not-A-Number to indicate an error
    }
    return result;
}


//Logarithmic and Exponential Operations

float Calculator::naturalLog(float x) {
    
    return std::log(x);
}

float Calculator::commonLog(float x) {
    
    return std::log10(x);
}  

float Calculator::exp(float x) {
    return std::exp(x);
}


//Matrix Operations

float Calculator::matrixDeterminant(float matrix[], int n) {
    if (n == 1) {
        return matrix[0];
    } else if (n == 2) {
        return matrix[0] * matrix[3] - matrix[1] * matrix[2];
    } else {
        float det = 0;
        float* submatrix = new float[(n - 1) * (n - 1)];
        for (int i = 0; i < n; ++i) {
            int subI = 0;
            for (int row = 1; row < n; ++row) {
                int subJ = 0;
                for (int col = 0; col < n; ++col) {
                    if (col == i) continue;
                    submatrix[subI * (n - 1) + subJ] = matrix[row * n + col];
                    ++subJ;
                }
                ++subI;
            }
            det += pow(-1, i) * matrix[i] * matrixDeterminant(submatrix, n - 1);
        }
        delete[] submatrix;
        return det;
    }
}

void Calculator::matrixInversion(float matrix[], int n) {
    float det = matrixDeterminant(matrix, n);
    if (det == 0) {
        cerr << "Error: Determinant is zero, matrix is singular." << endl;
        return;
    }

    float* inverse = new float[n * n];
    float* adjoint = new float[(n - 1) * (n - 1)];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int adjointI = 0;
            for (int row = 0; row < n; ++row) {
                if (row == i) continue;
                int adjointJ = 0;
                for (int col = 0; col < n; ++col) {
                    if (col == j) continue;
                    adjoint[adjointI * (n - 1) + adjointJ] = matrix[row * n + col];
                    ++adjointJ;
                }
                ++adjointI;
            }
            inverse[i * n + j] = pow(-1, i + j) * matrixDeterminant(adjoint, n - 1) / det;
        }
    }

    cout << "Inverse matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << inverse[i * n + j] << "\t";
        }
        cout << endl;
    }

    delete[] inverse;
    delete[] adjoint;
}


float* Calculator::matrixAddition(float A[], float B[], int rows, int cols) {
    float* result = new float[rows * cols]; // Allocate memory for the result matrix
    for (int i = 0; i < rows * cols; ++i) {
        result[i] = A[i] + B[i]; // Perform addition and store the result in the result matrix
    }
    return result; // Return the result matrix
}


float* Calculator::matrixSubtraction(float A[], float B[], int rows, int cols) {
    float* result = new float[rows * cols]; // Allocate memory for the result matrix
    for (int i = 0; i < rows * cols; ++i) {
        result[i] = A[i] - B[i]; // Perform addition and store the result in the result matrix
    }
    return result; // Return the result matrix
}

float* Calculator::matrixMultiplication(float A[], float B[], int rows_A, int cols_A, int cols_B) {
    float* result = new float[rows_A * cols_B]; // Allocate memory for the result matrix

    // Perform matrix multiplication
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            float sum = 0.0;
            for (int k = 0; k < cols_A; ++k) {
                sum += A[i * cols_A + k] * B[k * cols_B + j];
            }
            result[i * cols_B + j] = sum; // Store the result in the result matrix
        }
    }

    return result; // Return the result matrix
}



// Some addtional Operations and Helper Functions

int Calculator::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

float Calculator::applyOperation(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}


float Calculator::arbitraryExponent(const float& n,const float& r)
{
    return pow(n,r);
}

float Calculator::squareRoot(const float& x)
{
    return sqrt(x);
}

float Calculator::cubeRoot(const float& x)
{
    return cbrt(x);
}

float Calculator::arbitraryRoot(const float& x,const float& n)
{
    if(x<0 )
    {
        cout<<"Error!!! Please try again "<<endl;
        abort();
    }
    return pow(x,1/n);
}










