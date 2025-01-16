#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <string>
using namespace std;

class Calculator {
private:
    const float PI ; const float E ; int precedence(char op); float applyOperation(float a, float b, char op);
public:
    //Deafult constructor
    Calculator();
    //Constants
    float getPI() const;
    float getEuler() const;
    //Permutation, Combination and Factorial
    int factorial(const int n);
    int permutation(const int n, const int r);
    int combination(const int n, const int r);
    //General Operations
    float addition(const vector<float>& v1);
    float subtraction(const vector<float>& v1);
    float multiplication(const vector<float>& v1);
    float division(const vector<float>& v1);
    float evaluateExpression(const string& expression);
    //Equational Operations
    void linearEquation(float a1, float a2, float b1, float b2, float c1, float c2);
    void quadraticSolution(float a, float b, float c);
    void cubicEquations(const double& a,const double& b,const double& c,const double& d);
    //Conversions
    float degreeToRadian(float degrees);
    float radianToDegree(float radians);
    float degreesToGrads(float degrees);
    float gradsToDegrees(float grads);
    float inchesToCentimeters(float inches);
    float centimetersToInches(float centimeters);
    float feetToMeters(float feet);
    float metersToFeet(float meters);
    float milesToKilometers(float miles);
    float kilometersToMiles(float kilometers);
    //Trigonometric Operations
    float sin(float x, bool isDegree); 
    float cos(float x, bool isDegree); 
    float tan(float x, bool isDegree); 
    float cosec(float x, bool isDegree); 
    float sec(float x, bool isDegree);   
    float cot(float x, bool isDegree);  
    float sinh(float& angle,bool isDegree);
    float cosh(float& angle,bool isDegree);
    float tanh(float& angle,bool isDegree);
    float cosech(float& angle,bool isDegree);
    float sech(float& angle,bool isDegree);
    float coth(float& angle,bool isDegree); 
    float angle(const float& value,const string& w);
    //Logarithmic and Exponential Operations
    float naturalLog(float x); 
    float commonLog(float x);
    float exp(float x);
    //Matrix Operations
    float matrixDeterminant(float matrix[], int n);
    void matrixInversion(float matrix[], int n);
    float* matrixAddition(float A[], float B[], int rows, int cols);
    float* matrixSubtraction(float A[], float B[], int rows, int cols);
    float* matrixMultiplication(float A[], float B[], int rows_A, int cols_A, int cols_B);
    //Some additional Operations
    float arbitraryExponent(const float& n,const float& r); 
    float squareRoot(const float& x);
    float cubeRoot(const float& x);
    float arbitraryRoot(const float& x,const float& n); // nth root of x
};

#endif