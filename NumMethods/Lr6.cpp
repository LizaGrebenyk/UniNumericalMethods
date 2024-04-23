#include <iostream>
#include <cmath>

using namespace std;

double fun(double);
double rectangleMethod(double, double, int);
double trapezoidalMethod(double, double, int);
double simpsonMethod(double, double, int);

int main()
{
    // Initialize the interval bounds and the number of intervals
    double a = 0.0, b = 1.2;
    int n = 10;

    // Integral that is to be calculated
    cout << "Calculation of the integral\n\033[36m/ (3.5x^2 + x)\n| ----------- dx\n/  (x^4 + 2)\033[0m\n on the interval \033[95m[" << a << ", " << b << "]\033[0m\n\n";

    // Results of the different numerical integration methods
    cout << "\033[32mRectangle Method:\t" << rectangleMethod(a, b, n) << "\033[0m\n\n";
    cout << "\033[33mTrapezoidal Method:\t" << trapezoidalMethod(a, b, n) << "\033[0m\n\n";
    cout << "\033[35mSimpson's Method:\t" << simpsonMethod(a, b, n) << "\033[0m\n\n";
    cout << "\033[34mWolframAlpha result:\t1.01161\033[0m\n\n";

    return 0;
}

double fun(double x)    // Function to calculate the value of the function at point x
{
    return (3.5 * pow(x, 2) + x) / (pow(x, 4) + 2);
}

double rectangleMethod(double a, double b, int n)   // Rectangle Method for numerical integration
{
    double h = (b - a) / n; // Width of each interval
    double sum = 0.0;

    for (int i = 0; i < n; i++) // Sum up the areas of each rectangle
        sum += fun(a + i * h + h / 2);

    return abs(sum * h);    // Multiply by the interval width and return the absolute value
}

double trapezoidalMethod(double a, double b, int n) // Trapezoidal Method for numerical integration
{
    double h = (b - a) / n; // Width of each interval
    double sum = (fun(a) + fun(b)) / 2.0;   // Average of the end points

    for (int i = 1; i < n; i++) // Sum up the function values at each interval point
        sum += fun(a + i * h);

    return abs(sum * h);    // Multiply by the interval width and return the absolute value
}

double simpsonMethod(double a, double b, int n) // Simpson's Method for numerical integration
{
    if (n % 2 != 0) // Simpson's rule requires an even number of intervals
        n++;

    double h = (b - a) / n; // Width of each interval
    double sum = fun(a) + fun(b); // End points

    for (int i = 1; i < n; i++) // Sum up the function values, weighted according to Simpson's rule
        sum += fun(a + i * h) * (i % 2 == 0 ? 2 : 4);

    return abs(sum * h / 3);    // Multiply by the interval width divided by 3 and return the absolute value
}
