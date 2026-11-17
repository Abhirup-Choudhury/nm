#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return x + y;
}

double rk4Step(double x, double y, double h)
{
    double k1 = h * f(x, y);
    double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
    double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
    double k4 = h * f(x + h, y + k3);
    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
}

void rungeKutta4(double x, double y, double h, int n)
{
    cout << "Runge-Kutta 4th Order Method\n";
    cout << "x\t\ty\n" << x << "\t" << y << "\n";
    for (int i = 0; i < n; ++i)
    {
        y = rk4Step(x, y, h);
        x += h;
        cout << x << "\t" << y << "\n";
    }
}

int main()
{
    double x = 0.0, y = 1.0, h = 0.1;
    int n = 5;

    cout << fixed << setprecision(6);
    rungeKutta4(x, y, h, n);
    return 0;
}
