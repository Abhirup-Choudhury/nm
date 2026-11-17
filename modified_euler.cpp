#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return x + y;
}

void modifiedEuler(double x, double y, double h, int n)
{
    cout << "x\t y\n";
    for (int i = 0; i < n; i++)
    {
        double k1 = f(x, y);
        double yPredict = y + h * k1;
        double k2 = f(x + h, yPredict);
        y = y + (h / 2.0) * (k1 + k2);
        x += h;
        cout << x << "\t " << y << "\n";
    }
}

int main()
{
    double x = 0.0, y = 1.0;
    double h = 0.1;
    int n = 5;
    cout << fixed << setprecision(4);
    modifiedEuler(x, y, h, n);
    return 0;
}
