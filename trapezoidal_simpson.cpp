#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return 1.0 / (16.0 + x * x);
}

double trapezoidalRule(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double x_i = a + i * h;
        sum += 2.0 * f(x_i);
    }
    return (h / 2.0) * sum;
}

double simpson13Rule(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double x_i = a + i * h;
        if (i % 2 == 0)
            sum += 2.0 * f(x_i);
        else
            sum += 4.0 * f(x_i);
    }
    return (h / 3.0) * sum;
}

double simpson38Rule(double a, double b, int n)
{
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double x_i = a + i * h;
        if (i % 3 == 0)
            sum += 2.0 * f(x_i);
        else
            sum += 3.0 * f(x_i);
    }
    return (3.0 * h / 8.0) * sum;
}

int main()
{
    double a, b;
    int n;

    cout << "Enter lower limit: ";
    cin >> a;
    cout << "Enter upper limit: ";
    cin >> b;
    cout << "Enter number of subintervals (n): ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of subintervals must be greater than 0." << "\n";
        return 1;
    }
    cout << fixed << setprecision(6);
    cout << "\n------------- Results -------------\n";

    cout << "Trapezoidal Rule:   " << trapezoidalRule(a, b, n) << "\n";

    if (n % 2 == 0)
        cout << "Simpson 1/3rd Rule: " << simpson13Rule(a, b, n) << "\n";
    else
        cout << "n should be a multiple of 2 for Simpson 1/3rd rule.\n";

    if (n % 3 == 0)
        cout << "Simpson's 3/8 Rule: " << simpson38Rule(a, b, n) << "\n";
    else
        cout << "n should be a multiple of 3 for Simpson 1/3rd rule.\n";

    return 0;
}
