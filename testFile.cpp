#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
    // Test cases...
    Calculator calc;
    cout << "Value of pi: " << calc.getPI() << endl;
    cout << "Value of Euler's number: " << calc.getEuler() << endl;
    int length;
    string r1, e1, expression;
    float a, b, c, a1, a2, b1, b2, c1, c2;

    cout << "Calculator Menu --->>>" << endl;
    cout << " 1) Addition : 'a' or 'A'." << endl;
    cout << " 2) Subtraction : 's' or 'S'." << endl;
    cout << " 3) Multiplicationthen : 'm' or 'M'." << endl;
    cout << " 4) Division : 'd' or 'D'." << endl;
    cout << " 5) Equation : 'e' or 'E'." << endl;
    cout << " 6) Trigonometric Values : 't' or 'T'." << endl;
    cout << " 7) Factorial : 'f' or 'F'." << endl;
    cout << " 8) Arbitrary Exponent : 'p' or 'P'." << endl;
    cout << " 9) Combination  and Permutation: 'c' or 'C'." << endl;
    cout <<" 10) Logarithm and Exponential : 'l' or 'L' "<<endl;
    cout<<"  11) Square, Cubic or Arbitrary roots : 'r' or 'R' "<<endl;
    cout<<"  12) Conversion : 'n' or 'N' "<<endl;
    cout<<"  13) Matrix Operations : 'mx' or 'MX' "<<endl;
    cout<<"  14) Determine Angle : 'da' or 'DA' "<<endl;
    cout<<"  15) Multiple Arithmetic Operations 'k' or 'K' "<<endl;
    cin >> r1;

    if (r1 == "a" || r1 == "A" || r1 == "s" || r1 == "S" || r1 == "m" || r1 == "M" || r1 == "d" || r1 == "D") {
    cout << "Enter the numbers one by one. Enter any non-numeric value to stop." << endl;

    vector<float> numbers;
    float p;
    while (true) {
        cout << "Enter a number: ";
        if (!(cin >> p)) {
            // If non-numeric value entered, stop input
            break;
        }
        numbers.push_back(p);
    }

    if (r1 == "a" || r1 == "A")
        cout << "The sum of all the numbers is = " << calc.addition(numbers) << endl; 
    else if (r1 == "s"|| r1 == "S")
        cout << "The final answer is = " << calc.subtraction(numbers) << endl;
    else if (r1 == "m" || r1 == "M")
        cout << "The final answer is = " << calc.multiplication(numbers) << endl;
    else if (r1 == "d" || r1 == "D")
        cout << "The final answer is = " << calc.division(numbers) << endl;
    }

    else if (r1 == "e" || r1 == "E") {
        cout << " Equation Menu ---> " << endl;
        cout << " 1)Linear :  'l' or 'L'" << endl;
        cout << " 2) Quadratic : 'q' or 'Q'" << endl;
        cout << " 3)Qubic :  'qu' or 'QU'" << endl;
        
        cin >> e1;

        if (e1 == "q") {
            cout << "Enter the value of the coefficient of x2" << endl;
            cin >> a;
            cout << "Enter the value of the coefficient of x" << endl;
            cin >> b;
            cout << "Enter the value of the constant" << endl;
            cin >> c;
            calc.quadraticSolution(a, b, c);
        } 
        else if (e1 == "l" || e1 == "L") {
            cout << "Enter the coefficient of x of the first equation" << endl;
            cin >> a1;
            cout << "Enter the coefficient of y of the first equation" << endl;
            cin >> b1;
            cout << "Enter the constant of the first equation" << endl;
            cin >> c1;
            cout << "Enter the coefficient of x of the second equation" << endl;
            cin >> a2;
            cout << "Enter the coefficient of x of the second equation" << endl;
            cin >> b2;
            cout << "Enter the constant of the second equation" << endl;
            cin >> c2;
            calc.linearEquation(a1, a2, b1, b2, c1, c2);
        }
        else if(e1=="qu" || e1=="QU")
        {
            double a,b,c,d;
            cout << "Enter the value of the coefficient of x3" << endl;
            cin >> a;
            cout << "Enter the value of the coefficient of x2" << endl;
            cin >> b;
            cout << "Enter the value of the coefficient of x" << endl;
            cin >> c;
            cout << "Enter the value of the constant" << endl;
            cin >> d;
            calc.cubicEquations(a,b,c,d);


        }
    } 
    else if (r1 == "f" || r1 == "F") {
        int n;
        cout << "Enter the value of n: " << endl;
        cin >> n;
        cout << calc.factorial(n) << endl;
    } 
    else if (r1 == "p" || r1 == "P") {
        float n, r;
        cout << "Enter the value of n: " << endl;
        cin >> n;
        cout << "Enter the value of r: " << endl;
        cin >> r;
        cout << calc.arbitraryExponent(n, r) << endl;
    } 
    else if (r1 == "c" || r1 == "C") {
        string ch;
        cout<<"Menu ---> "<<endl;
        cout<<" 1) Permuation : p "<<endl;
        cout<<" 2) Combination : c "<<endl;
        if(ch=="c"){
        int n, r;
        cout << "Enter the value of n: " << endl;
        cin >> n;
        cout << "Enter the value of r: " << endl;
        cin >> r;
        cout << calc.combination(n, r) << endl;
        }
        else{
        float n, r;
        cout << "Enter the value of n: " << endl;
        cin >> n;
        cout << "Enter the value of r: " << endl;
        cin >> r;
        cout<<calc.permutation(n,r)<<endl;
        }
    } 
    else if (r1 == "t" || r1 == "T") {
        float x;
        string w;
        bool isDegree = false;
        cout << "Enter what ratio of x you want to find?" << endl;
        cout << " 1) Sine :'sin'" << endl;
        cout << " 2) Cosine :'cos'" << endl;
        cout << " 3) Tangent :'tan'" << endl;
        cout << " 4) Cosec :'cosec'" << endl;
        cout << " 5) Sec :'sec'" << endl;
        cout << " 6) Cot :'cot'" << endl;
        cout  <<" 7) Sinh : 'sinh' "<<endl; 
        cout  <<" 8) Cosh : 'cosh' "<<endl; 
        cout  <<" 9) Tanh : 'tanh' "<<endl; 
        cout  <<" 10)Cosechh : 'cosech' "<<endl; 
        cout  <<" 11)Sech : 'sech' "<<endl; 
        cout  <<" 12)Coth : 'coth' "<<endl; 
        cin >> w;
        cout << "Enter the value of x" << endl;
        cin >> x;
        if (w == "sin" || w == "cos" || w == "tan" || w == "cosec" || w == "sec" || w == "cot") {
            cout << "Is the angle in degrees? (y/n)" << endl;
            char degChoice;
            cin >> degChoice;
            if (degChoice == 'y' || degChoice == 'Y')
                isDegree = true;
        }
        if (w == "sin") {
            cout << "The final answer is = " << calc.sin(x, isDegree) << endl;
        } else if (w == "cos") {
            cout << "The final answer is = " << calc.cos(x, isDegree) << endl;
        } else if (w == "tan") {
            cout << "The final answer is = " << calc.tan(x, isDegree) << endl;
        } else if (w == "cosec") {
            cout << "The final answer is = " << calc.cosec(x, isDegree) << endl;
        } else if (w == "sec") {
            cout << "The final answer is = " << calc.sec(x, isDegree) << endl;
        } else if (w == "cot") {
            cout << "The final answer is = " << calc.cot(x, isDegree) << endl;
        } else if(w=="sinh"){
            cout << "The final answer is = " << calc.sinh(x, isDegree) << endl;   
        }else if(w=="cosh"){
            cout << "The final answer is = " << calc.cosh(x, isDegree) << endl;   
        }else if(w=="tanh"){
            cout << "The final answer is = " << calc.tanh(x, isDegree) << endl;   
        }else if(w=="cosech"){
            cout << "The final answer is = " << calc.cosech(x, isDegree) << endl;   
        }else if(w=="sech"){
            cout << "The final answer is = " << calc.sech(x, isDegree) << endl;   
        }else if(w=="coth"){
            cout << "The final answer is = " << calc.coth(x, isDegree) << endl;   
        }else {
            cerr << "Invalid input! Please enter a valid trigonometric function." << endl;
            // Handle the error, maybe ask for input again or terminate the function
            return 1;
        }
    }
    else if(r1 == "l" || r1 =="L")
    {
        float x;
        string w;
        cout<<" Menu --> "<<endl;
        cout<<" Logarothm : log "<<endl;
        cout<<" Exponential : exp "<<endl;
        cin>>w;
        if(w=="log")
        {
            string ch;
            cout<<"Logarithmic Menu ---> "<<endl;
            cout<<" 1) Natural Log : n "<<endl;
            cout<<" 2) Common Log : c "<<endl;
            cout<<"Enter : "<<endl;
            cin>>ch;
            if(ch=="n") 
                cout << "The final answer is = " << calc.naturalLog(x) << endl;
            else
                cout<<"The final answer is = "<<calc.commonLog(x)<<endl;
        }
        else if(w=="exp"){
            cout << "The final answer is = " << calc.exp(x) << endl;
        } else {
            cout << "Invalid input! Please enter a valid trigonometric function." << endl;
            // Handle the error, maybe ask for input again or terminate the function
            return 1;
        }
    }
    else if(r1=="r"||r1=="R")
    {
        string ch;
        double x;
        double n;
        cout<<"Roots Menu ---> "<<endl;
        cout<<" 1) Square Root : 's' or 'S'"<<endl;
        cout<<" 2) Cube Root :'c' or 'C'"<<endl;
        cout<<" 3) Others : 'o' or 'O' "<<endl;
        cin>>ch;
        cout<<"Enter the value of x "<<endl;
        cin>>x;
        if(ch=="s"|| ch=="S")
            cout<<"The answer is = "<<calc.squareRoot(x)<<endl;
        else if(ch=="c" || ch=="C")
            cout<<"The answer is = "<<calc.cubeRoot(x)<<endl;
        else if(ch=="o" || ch=="O")
        {
            cout<<"Enter the value of n "<<endl;
            cin>>n;
            cout<<"The answer is = "<<calc.arbitraryRoot(x,n)<<endl;
        }
    }
    else if(r1=="n" || r1=="N")
    {
        cout<<"Conversion Menu ---> "<<endl;
        cout<<" 1) Degrees to Radians : d "<<endl;
        cout<<" 2) Radians to Degrees : r "<<endl;
        cout<<" 3) Degrees to Gradians : dg "<<endl;
        cout<<" 4) Gradians to Degrees : gd "<<endl;
        cout<<" 5) Cm to Inch : c "<<endl;
        cout<<" 6) Inch to cm : i "<<endl;
        cout<<" 7) Feets to Meters : f "<<endl;
        cout<<" 8) Metres to feets : m "<<endl;
        cout<<" 9) Miles to Km : mi "<<endl;
        cout<<" 10)Km to Miles : k "<<endl;
        string ch;
        cin>>ch;
        float x;
        if(ch=="d")
        {
            cout<<"Enter the value of x( in degrees )"<<endl;
            cin>>x;
            cout << x << " degrees is equal to " << calc.degreeToRadian(x) << " radians." << endl;
        }
        else if(ch=="r")
        {
            cout<<"Enter the value of x( in randians )"<<endl;
            cin>>x;
            cout << x << " radians is equal to " << calc.radianToDegree(x) << " radians." << endl;
        }
        else if(ch=="dg")
        {
            cout<<"Enter the value of x( in degree )"<<endl;
            cin>>x;
            cout << x << " degrees is equal to " << calc.degreesToGrads(x) << " gradians" << endl;
        }
        else if(ch=="gd")
        {
            cout<<"Enter the value of x( in gradians )"<<endl;
            cin>>x;
            cout << x << " degrees is equal to " << calc.gradsToDegrees(x) << " radians." << endl;
        }
        else if( ch=="c")
        {
            cout<<"Enter the value of x( in cm )"<<endl;
            cin>>x;
            cout<<x<<" cm is equal to "<<calc.centimetersToInches(x)<<" inches "<<endl;
        }
        else if( ch=="i")
        {
            cout<<"Enter the value of x( in inches )"<<endl;
            cin>>x;
            cout<<x<<" inches is equal to "<<calc.inchesToCentimeters(x)<<" cm "<<endl;
        }
        else if( ch=="f")
        {
            cout<<"Enter the value of x( in feets )"<<endl;
            cin>>x;
            cout<<x<<" feets is equal to "<<calc.feetToMeters(x)<<" meters "<<endl;
        }
        else if( ch=="m")
        {
            cout<<"Enter the value of x( in meters )"<<endl;
            cin>>x;
            cout<<x<<" meters is equal to "<<calc.metersToFeet(x)<<" feetrs "<<endl;
        }
        else if( ch=="mi")
        {
            cout<<"Enter the value of x( in miles )"<<endl;
            cin>>x;
            cout<<x<<" miles is equal to "<<calc.milesToKilometers(x)<<" km "<<endl;
        }
        else if(ch=="k")
        {
            cout<<"Enter the value of x( in km )"<<endl;
            cin>>x;
            cout<<x<<" km is equal to "<<calc.kilometersToMiles(x)<<" miles "<<endl;
        }

    }
    else if(r1=="mx" || r1=="MX")
    {
        string ch;
        cout<<"Matrix Operations Menu ----> "<<endl;
        cout<<" 1) Determinant : 'd' "<<endl;
        cout<<" 2)Inversion : 'i' "<<endl;
        cout<<" 3) Matrix Addition: 'a' "<<endl;
        cout<<" 4) Matrix Substraction : 's ' "<<endl;
        cout<<" 5) Matrix Multiplication: 'm' "<<endl;
        cin>>ch;
        if(ch=="d")
        {
            int r,c;
            cout<<"Enter the number of rows "<<endl;
            cin>>r;
            cout<<"Enter the number of column "<<endl;
            cin>>c;
            float matrixA[r*c];
            cout<<"Enter elemnts for the matrix "<<endl;
            for(size_t i=0;i<r*c;i++){
                cout<<"Enter element "<<i+1<<" is : ";
                cin>>matrixA[i];
            }
            cout<<" Determinant of the matrix is "<<calc.matrixDeterminant(matrixA,r)<<endl;
        }
        else if(ch=="i")
        {
            int r,c;
            cout<<"Enter the number of rows "<<endl;
            cin>>r;
            cout<<"Enter the number of column "<<endl;
            cin>>c;
            float matrixA[r*c];
            cout<<"Enter elements of the matrix "<<endl;
            for(size_t i=0;i<r*c;i++){
                cout<<"Enter element "<<i+1<<" is : ";
                cin>>matrixA[i];
            }
            cout<<" Inverse matrix is --->  " ;
            calc.matrixInversion(matrixA,r);
        }
        else if (ch == "a") {
            // Matrix addition
            int rows, cols;
            cout << "Enter the number of rows: ";
            cin >> rows;
            cout << "Enter the number of columns: ";
            cin >> cols;

            // Input matrices A and B
            float A[rows * cols];
            float B[rows * cols];
            cout << "Enter elements of the first matrix : "<<endl;
            for (int i = 0; i < rows * cols; ++i) {
                cout<<"Enter element "<<i+1<<" : ";
                cin >> A[i];
            }
            cout << "Enter elements of the second matrix B: "<<endl;
            for (int i = 0; i < rows * cols; ++i) {
                cout<<"Enter element "<<i+1<<" : ";
                cin >> B[i];
            }

            // Perform matrix addition
            float* result = calc.matrixAddition(A, B, rows, cols);

            // Display the result
            cout << "Result of matrix addition:" << endl;
            for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << result[i * cols + j] << " ";
            }
            cout << endl;
            }
            delete[] result;
        }

        else if(ch=="s")
        {
            int rows, cols;
            cout << "Enter the number of rows: ";
            cin >> rows;
            cout << "Enter the number of columns: ";
            cin >> cols;

            // Input matrices A and B
            float A[rows * cols];
            float B[rows * cols];
            cout << "Enter elements of the first matrix : "<<endl ;
            for (int i = 0; i < rows * cols; ++i) {
                cout<<"Enter element "<<i+1<<" : ";
                cin >> A[i];
            }
            cout << "Enter elements of the second matrix : "<<endl;
            for (int i = 0; i < rows * cols; ++i) {
                cout<<"Enter element "<<i+1<<" : ";
                cin >> B[i];
            }

            float* result = calc.matrixSubtraction(A, B, rows, cols);

            // Display the result
            cout << "Result of matrix addition:" << endl;
            for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << result[i * cols + j] << " ";
            }
            cout << endl;
            }
            delete[] result;
        }

        else if(ch=="m")
        {
            int rows_A, cols_A, cols_B;
            cout << "Enter the number of rows of the first matrix : ";
            cin >> rows_A;
            cout << "Enter the number of columns of the first matrix : ";
            cin >> cols_A;
            cout << "Enter the number of columns of the second matrix : ";
            cin >> cols_B;

            // Input matrices A and B
            float A[rows_A * cols_A];
            float B[cols_A * cols_B];
            cout << "Enter elements of the first matrix : "<<endl;
            for (int i = 0; i < rows_A * cols_A; i++) {
                cout<<"Enter element "<<i+1<<" : ";
                cin >> A[i];
            }
            cout << "Enter elements of the second matrix : "<<endl;
            for (int i = 0; i < cols_A * cols_B; i++) {
                cout<<"Enter element "<<i+1<<" : ";
                cin >> B[i];
            }

            // Performing matrix multiplication
            float* result = calc.matrixMultiplication(A, B, rows_A, cols_A, cols_B);

            // Displaying the result
            cout << "Result of matrix multiplication:" << endl;
            for (int i = 0; i < rows_A; i++) {
            for (int j = 0; j < cols_B; j++) {
                cout << result[i * cols_B + j] << " ";
            }
            cout << endl;
            }
            delete[] result;
            }

    }
    else if(r1=="da"|| r1=="DA"){
            string u;
            float value;
            cout<<"Menu ----> "<<endl;
            cout<<"1) Sine : 'sin' "<<endl;
            cout << " 2) Cosine :'cos'" << endl;
            cout << " 3) Tangent :'tan'" << endl;
            cout << " 4) Cosec :'cosec'" << endl;
            cout << " 5) Sec :'sec'" << endl;
            cout << " 6) Cot :'cot'" << endl;
            cout  <<" 7) Sinh : 'sinh' "<<endl; 
            cout  <<" 8) Cosh : 'cosh' "<<endl; 
            cout  <<" 9) Tanh : 'tanh' "<<endl; 
            cout  <<" 10)Cosechh : 'cosech' "<<endl; 
            cout  <<" 11)Sech : 'sech' "<<endl; 
            cout  <<" 12)Coth : 'coth' "<<endl; 
            cin>>u;
            cout<<"Enter the value "<<endl;
            cin>>value;
            float result= calc.angle(value,u);
            cout<<"The angle in radian "<<result<<endl;
            float result1=calc.radianToDegree(result);
            cout<<"The angle in degree "<<result1<<endl;
            float result2= calc.degreesToGrads(result1);
            cout<< "The angle in gradian "<<result2<<endl;

        }
        else if(r1=="k" || r1=="K")
        {
            cin.ignore();
            cout<<"Enter the arithmetic operations: "<<endl;
            getline(cin,expression);
            float result = calc.evaluateExpression(expression);
            cout<<"Answer = "<<result<<endl;
        }
    return 0;

}
