#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double cubicEquation(double, double, double, double, double);
double dichotomyMethod(double, double, double, double, double, double, double);
bool hasRoot(double, double, double, double, double, double);
vector<pair<double, double>> findIntervals(double a, double b, double c, double d, double start, double end, double step);
double calculateAbsoluteError(double, double);

int main() 
{
    double a = -2.9,    // Coefficients of the cubic equation
        b = -1.5, 
        c = -4.6, 
        d = 0.5;
    double epsilon = 10e-4, // Tolerance for the root finding process
        left = -100, right = 100,   // Search bounds for the root
        step = 0.1; // Step size for interval search

    // Display the cubic equation
    cout << "Cubic equation: \033[32m" << a << "\033[0mx^3 + \033[32m" 
        << b << "\033[0mx^2 + \033[32m" 
        << c << "\033[0mx + \033[32m" 
        << d << "\033[0m = 0" << endl << endl;

    // Find intervals where the cubic equation might have roots
    vector<pair<double, double>> intervals = findIntervals(a, b, c, d, left, right, step);
    vector<double> root;
    for (const auto& interval : intervals) 
    {
        root.push_back(dichotomyMethod(a, b, c, d, interval.first, interval.second, epsilon));  // Use the dichotomy method to find a root within each interval
        cout << "The root " << root.size() << " is found in the interval [\033[33m" << interval.first << " \033[0m;\033[33m "
            << interval.second << "\033[0m]: \033[34m" << root[root.size() - 1] << "\033[0m\n\n";
    }

    cout << "Absolute errors:" << endl; // Display the absolute errors of the found roots
    for (int i = 0; i < root.size(); i++)
        cout << "Root " << i + 1 << " = \033[35m" << calculateAbsoluteError(0, cubicEquation(root[i],a,b,c,d)) << " \033[0m\n";

    return 0;
}

double cubicEquation(double x, double a, double b, double c, double d)  // Function to evaluate the cubic equation at x
{
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

double dichotomyMethod(double a, double b, double c, double d, double left, double right, double epsilon)   // Dichotomy (bisection) method to find the root within a given interval
{
    if (!hasRoot(a, b, c, d, left, right))
    {
        cout << "\033[31mThere is no root in this interval\033[0m" << endl;
        return 0;
    }

    int iterationCount = 0;
    double mid = left;
    while (abs(cubicEquation(mid, a, b, c, d)) > epsilon)
    {
        iterationCount++;

        mid = (left + right) / 2;
        if (cubicEquation(mid, a, b, c, d) == 0)    // Check if the mid-point is a root or sufficiently close to being one
            break;
        
        if (hasRoot(a, b, c, d, left, mid)) // Determine which half of the interval contains the root and update the interval accordingly
            right = mid;
        else
            left = mid;
    }

    cout << "Number of iterations: \033[36m" << iterationCount << "\033[0m\n";
    return mid;
}

bool hasRoot(double a, double b, double c, double d, double left, double right) // Check if there is a root in the interval [left, right] by checking for a sign change
{
    return cubicEquation(left, a, b, c, d) * cubicEquation(right, a, b, c, d) < 0;
}

vector<pair<double, double>> findIntervals(double a, double b, double c, double d, double start, double end, double step)   // Find intervals where the cubic equation may have roots by checking for sign changes
{
    vector<pair<double, double>> intervals;
    double left = start, 
        right;

    while (left < end)
    {
        right = left + step;
        if (hasRoot(a, b, c, d, left, right))   // If a root exists within this small interval, add it to the list of potential intervals
            intervals.push_back({ left, right });

        left = right;
    }

    return intervals;
}

double calculateAbsoluteError(double trueValue, double approximateValue)    // Calculate the absolute error between the true value and the approximate value
{
    return abs(trueValue - approximateValue);
}