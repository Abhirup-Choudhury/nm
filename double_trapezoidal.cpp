#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return 1.0 / (x + y);
}

double doubleTrapezoidal(double x0, double xn, double y0, double ym, int n, int m)
{
    double h = (xn - x0) / n;
    double k = (ym - y0) / m;
    vector<double> wx(n + 1, 2.0), wy(m + 1, 2.0);
    wx[0] = wx[n] = 1.0;
    wy[0] = wy[m] = 1.0;

    double totalSum = 0.0;
    for (int i = 0; i <= n; ++i)
    {
        double x = x0 + i * h;
        for (int j = 0; j <= m; ++j)
        {
            double y = y0 + j * k;
            totalSum += wx[i] * wy[j] * f(x, y);
        }
    }
    return (h * k / 4.0) * totalSum;
}

int main()
{
    double x_min, x_max;
    double y_min, y_max;
    int n, m;

    cout << "=== Double Trapezoidal Rule for Numerical Integration ===" << endl;
    cout << "Enter lower and upper limits for x: ";
    cin >> x_min >> x_max;

    cout << "Enter lower and upper limits for y: ";
    cin >> y_min >> y_max;

    cout << "Enter number of subintervals for x (n) and y (m): ";
    cin >> n >> m;

    if (n <= 0 || m <= 0)
    {
        cout << "Subintervals must be positive integers." << endl;
        return 0;
    }

    double result = doubleTrapezoidal(x_min, x_max, y_min, y_max, n, m);

    cout << fixed << setprecision(6);
    cout << "---------------- Integration Results ----------------" << endl;
    cout << "Approximate Integral Value = " << result << endl;
    cout << "-----------------------------------------------------" << endl;

    return 0;
}
