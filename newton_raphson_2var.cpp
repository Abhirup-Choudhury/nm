#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return x * x + y * y - 4.0;
}

double g(double x, double y)
{
    return x - y;
}

double f_x(double x, double y) { return 2.0 * x; }
double f_y(double x, double y) { return 2.0 * y; }

double g_x(double x, double y) { return 1.0; }
double g_y(double x, double y) { return -1.0; }

vector<double> newtonRaphson2Var(double x, double y, double tol, int max_iterations)
{
    cout << "Iteration\t\tx\t\ty\t\th\t\tk\n";
    cout << "---------------------------------------------------------\n";

    for (int iter = 1; iter <= max_iterations; ++iter)
    {
        double f_val = f(x, y);
        double g_val = g(x, y);
        double df_x = f_x(x, y);
        double df_y = f_y(x, y);
        double dg_x = g_x(x, y);
        double dg_y = g_y(x, y);
        double D = df_x * dg_y - dg_x * df_y;
        double Dx = f_val * dg_y - g_val * df_y;
        double Dy = df_x * g_val - f_val * dg_x;

        double h = -Dx / D;
        double k = -Dy / D;
        cout << iter << "\t\t" << x << "\t" << y << "\t" << h << "\t" << k << "\n";

        x = x + h;
        y = y + k;

        if (abs(h) < tol && abs(k) < tol)
        {
            cout << "Solution: x = " << x << ", y = " << y << "\n";
            break;
        }
    }
    return {x, y};
}

int main()
{
    double x = 1.0;
    double y = 1.0;
    double tol = 1e-6;
    int max_iterations = 100;

    cout << fixed << setprecision(6);
    newtonRaphson2Var(x, y, tol, max_iterations);
    return 0;
}
