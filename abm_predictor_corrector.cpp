#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return x + y;
}

double exact(double x)
{
    return 2 * exp(x) - x - 1;
}

double rk4Step(double x, double y, double h)
{
    double k1 = h * f(x, y);
    double k2 = h * f(x + h / 2.0, y + k1 / 2.0);
    double k3 = h * f(x + h / 2.0, y + k2 / 2.0);
    double k4 = h * f(x + h, y + k3);
    return y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
}

void printRow(double x, double y)
{
    cout << x << "\t" << y << "\t" << exact(x) << "\t" << fabs(y - exact(x)) << "\n";
}

void adamsBashforthMoulton(double x0, double y0, double h, int n)
{
    int size = max(n, 3) + 1;
    vector<double> x(size), y(size);
    x[0] = x0;
    y[0] = y0;

    for (int i = 0; i < 3; i++)
    {
        y[i + 1] = rk4Step(x[i], y[i], h);
        x[i + 1] = x[i] + h;
    }

    cout << "\n x\t\t y_numeric\t\t y_exact\t\t Error\n";
    for (int i = 0; i <= 3; i++)
        printRow(x[i], y[i]);

    for (int i = 3; i < n; i++)
    {
        double yp = y[i] + (h / 24) * (55 * f(x[i], y[i]) - 59 * f(x[i - 1], y[i - 1]) + 37 * f(x[i - 2], y[i - 2]) - 9 * f(x[i - 3], y[i - 3]));

        double xNext = x[i] + h;

        double yc = y[i] + (h / 24) * (9 * f(xNext, yp) + 19 * f(x[i], y[i]) - 5 * f(x[i - 1], y[i - 1]) + f(x[i - 2], y[i - 2]));

        x[i + 1] = xNext;
        y[i + 1] = yc;
        printRow(x[i + 1], y[i + 1]);
    }
}

int main()
{
    double x0, y0, h;
    int n;

    cout << "Enter initial value x0: ";
    cin >> x0;
    cout << "Enter initial value y0: ";
    cin >> y0;
    cout << "Enter step size h: ";
    cin >> h;
    cout << "Enter number of steps: ";
    cin >> n;

    cout << fixed << setprecision(6);
    adamsBashforthMoulton(x0, y0, h, n);
    return 0;
}
