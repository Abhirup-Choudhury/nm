#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return x + y;
}

double euler(double x0, double y0, double x_target, double h)
{
    double x = x0;
    double y = y0;

    int steps = (x_target - x0) / h;
    for (int i = 0; i < steps; ++i)
    {
        y += h * f(x, y);
        x += h;
    }
    return y;
}

int main()
{
    double x0, x_target, y0, h;

    cout << "Enter lower limit (x0): ";
    cin >> x0;
    cout << "Enter initial value at lower limit (y0): ";
    cin >> y0;
    cout << "Enter upper limit (x_target): ";
    cin >> x_target;
    cout << "Enter step size (h): ";
    cin >> h;

    double result = euler(x0, y0, x_target, h);

    cout << "Approximate solution y(" << x_target << ") = " << fixed << setprecision(6) << result << endl;

    return 0;
}
