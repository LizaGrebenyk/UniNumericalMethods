#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;
using matrix = vector<vector<double>>;

bool checkConvergence(const matrix&);
void maximizeDiagonal(matrix&, vector<double>&);
vector<double> simpleIterationMethod(matrix&, vector<double>, double, vector<double>);
double calculateDeterminant(const matrix&);
bool checkDeterminant(const matrix&, double);
double promptDoubleInput(const string&);
void printSystem(matrix&, vector<double>, vector<double>);
double calculateAbsoluteError(double, double);
double calculateApproximateValue(vector<double>, vector<double>);

void main()
{
    double m = promptDoubleInput("Enter m: ");
    matrix matrix = { {5, 1, -1, 1 },
                    {1, -4, 1, -1 },
                    {-1, 1, 4, 1 },
                    {1, 2, 1, -5 } };
    vector<double> b = { 3 * m, m - 6, 15 - m, m + 2 };
    vector<double> x0 = { 0.7 * m, 1, 2, 0.5 }; // Initial approximation
    double epsilon = 0.005;

    printSystem(matrix, b, x0);

    maximizeDiagonal(matrix, b);
    if (!checkConvergence(matrix) || checkDeterminant(matrix,epsilon))
    {
        cout << "\033[31mThe system is not convergent or has no solutions. Check the convergence conditions\033[31m" << endl;
        return;
    }

    vector<double> result = simpleIterationMethod(matrix, b, epsilon, x0);
    cout << "Result:" << endl;
    for (int i = 0; i < result.size(); i++)
        cout << "x" << i + 1 << " = \033[35m" << result[i] << "\033[0m\n";


    cout << "\nAbsolute errors:" << endl;
    for (int i = 0; i < matrix.size(); i++)
        cout << "b" << i + 1 << " = \033[43m " << calculateAbsoluteError(b[i], calculateApproximateValue(matrix[i], result)) << " \033[0m\n";
}

// Function for checking system convergence
bool checkConvergence(const matrix& mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        double sum = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (i != j)
                sum += abs(mat[i][j]);
        }
        if (abs(mat[i][i]) <= sum)
            return false;   // The system is not convergent
    }
    return true;    // The system is convergent
}

void maximizeDiagonal(matrix& mat, vector<double>& b) 
{
    int n = mat.size();

    for (int i = 0; i < n; ++i) 
    {
        int maxRow = i;
        double maxElem = abs(mat[i][i]);

        for (int j = i + 1; j < n; j++) // Find the maximum element in a column
        {
            if (abs(mat[j][i]) > maxElem) 
            {
                maxElem = abs(mat[j][i]);
                maxRow = j;
            }
        }

        if (maxRow != i)    // Swap the rows of the matrix if we found a larger element
        {
            swap(mat[i], mat[maxRow]);
            swap(b[i], b[maxRow]);
        }
    }
}

// A function for solving a system of linear equations by the simple iteration method
vector<double> simpleIterationMethod(matrix& mat, vector<double> b, double epsilon, vector<double> x0)
{
    int n = b.size();
    vector<double> prevX = x0;
    bool flag = true;
    int iterationCount = 0;

    while (flag)
    {
        iterationCount++;
        for (int i = 0; i < n; i++)
        {
            double sum = b[i];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    sum -= mat[i][j] * prevX[j];
            }
            x0[i] = round((sum / mat[i][i]) * 1000) / 1000.0;
            //x0[i] = sum / mat[i][i];
        }

        double maxD = abs(x0[0] - prevX[0]);
        for (int i = 1; i < n; i++)
        {
            if (abs(x0[i] - prevX[i]) > maxD)
                maxD = abs(x0[i] - prevX[i]);
        }

        if (maxD < epsilon)
            flag = false;

        prevX = x0; // Preparing for the next iteration
    }

    cout << "Number of iterations: \033[36m" << iterationCount << "\033[0m\n\n";
    return x0;
}

double calculateDeterminant(const matrix& mat) 
{
    int dimension = mat.size();
    double determinant = 0;

    if (dimension == 1)
        return mat[0][0];

    if (dimension == 2)
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    for (int i = 0; i < dimension; i++) 
    {
        matrix subMatrix(dimension - 1, vector<double>(dimension - 1)); // Creating a matrix of smaller size (n-1)x(n-1)

        for (int subRow = 1; subRow < dimension; subRow++) 
        {
            for (int subCol = 0; subCol < dimension; subCol++) 
            {
                if (subCol < i)
                    subMatrix[subRow - 1][subCol] = mat[subRow][subCol];
                else if (subCol > i)
                    subMatrix[subRow - 1][subCol - 1] = mat[subRow][subCol];
            }
        }

        double subDeterminant = calculateDeterminant(subMatrix);    // Using recursion to calculate the determinant of a smaller matrix

        determinant += (i % 2 == 0 ? 1 : -1) * mat[0][i] * subDeterminant;  // Add or subtract the calculated determinant depending on the position
    }

    return determinant;
}

bool checkDeterminant(const matrix& mat, double epsilon) 
{
    double det = calculateDeterminant(mat);
    return abs(det) < epsilon;
}

double promptDoubleInput(const string& promptMessage) 
{
    double value;
    while (true)    // An infinite loop that runs until the user enters a valid value
    {
        cout << promptMessage;
        cin >> value;

        if (cin.fail()) // If the value entered is not a number
        { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Ignore incorrect input until the end of the line
            cout << "Invalid value entered. Please enter a number\n";
        }
        else 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Ignore the rest of the input until the end of the line
            break;
        }
    }
    return value;   // Return the correct numerical value
}

void printSystem(matrix& mat, vector<double> b, vector<double> x0)
{
    cout << "\nSystem of linear equations:"<<endl;
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
            cout << (j == 0 ? "\033[32m" : " + \033[32m") << mat[i][j] << "\033[0mx" << (j + 1);
        cout << " = \033[34m" << b[i] << "\033[0m\n";
    }
    cout << endl;

    cout << "Initial approximation: \nx0 = {";
    for (int i = 0; i < x0.size(); i++)
        cout << "\033[33m" << x0[i] << (i == x0.size() - 1 ? " \033[0m" : "\033[0m; ");
    cout << "}\n" << endl;
}

double calculateAbsoluteError(double trueValue, double approximateValue) 
{
    return abs(trueValue - approximateValue);
}

double calculateApproximateValue(vector<double> row, vector<double> x)
{
    double sum = 0;
    for (int i = 0; i < row.size(); i++)
        sum += row[i] * x[i];

    return sum;
}