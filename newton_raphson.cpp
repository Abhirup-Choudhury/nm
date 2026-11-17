#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x - 3 * x - 5;
}

double fx(double x)
{
    return 3 * x * x - 3;
}

double newtonRaphson(double x0, double tol, int max_iterations)
{
    double x1 = x0;
    cout << "Iteration\tSoln\n";
    for (int iter = 1; iter <= max_iterations; iter++)
    {
        x1 = x0 - f(x0) / fx(x0);
        cout << iter << "\t\t" << x1 << endl;
        if (abs(x1 - x0) < tol)
            break;
        x0 = x1;
    }
    return x1;
}

int main()
{
    double x0 = 2.0;
    double tol = 1e-6;
    int max_iterations = 15;

    cout << fixed << setprecision(6);
    double root = newtonRaphson(x0, tol, max_iterations);
    cout << "\nApproximate Solution = " << root << endl;
    return 0;
}
