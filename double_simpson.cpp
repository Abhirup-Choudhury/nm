#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return x * x + y * y;
}

vector<double> simpsonWeights(int n)
{
    vector<double> w(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0 || i == n)
            w[i] = 1;
        else if (i % 2 == 1)
            w[i] = 4;
        else
            w[i] = 2;
    }
    return w;
}

double doubleSimpson13(double a, double b, double c, double d, int nx, int ny)
{
    double hx = (b - a) / nx;
    double hy = (d - c) / ny;
    vector<double> wx = simpsonWeights(nx);
    vector<double> wy = simpsonWeights(ny);

    double sum = 0;
    for (int i = 0; i <= nx; i++)
    {
        double x = a + i * hx;
        for (int j = 0; j <= ny; j++)
        {
            double y = c + j * hy;
            sum += wx[i] * wy[j] * f(x, y);
        }
    }
    return (hx * hy / 9.0) * sum;
}

int main()
{
    double a, b, c, d;
    int nx, ny;
    cout << "Enter lower limit of x: ";
    cin >> a;
    cout << "Enter upper limit of x: ";
    cin >> b;
    cout << "Enter lower limit of y: ";
    cin >> c;
    cout << "Enter upper limit of y: ";
    cin >> d;
    cout << "Enter number of subintervals for x: ";
    cin >> nx;
    cout << "Enter number of subintervals for y: ";
    cin >> ny;
    if (nx <= 0 || ny <= 0 || nx % 2 != 0 || ny % 2 != 0)
    {
        cout << "Number of subintervals must be positive and even." << endl;
        return 1;
    }
    double integral = doubleSimpson13(a, b, c, d, nx, ny);
    cout << "Approximate value of double integral = " << integral << endl;
    return 0;
}
