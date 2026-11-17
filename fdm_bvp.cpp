#include <bits/stdc++.h>
using namespace std;

double p(double x) { return 2.0; }
double q(double x) { return 1.0; }
double r(double x) { return 1.0; }

vector<double> thomas(const vector<double> &a,
                      const vector<double> &b,
                      const vector<double> &c,
                      const vector<double> &d)
{
    int n = b.size();
    vector<double> cp(n, 0.0);
    vector<double> dp(n, 0.0);
    vector<double> x(n, 0.0);

    cp[0] = c[0] / b[0];
    dp[0] = d[0] / b[0];
    for (int i = 1; i < n; ++i)
    {
        double m = b[i] - a[i] * cp[i - 1];
        cp[i] = (i < n - 1) ? c[i] / m : 0.0;
        dp[i] = (d[i] - a[i] * dp[i - 1]) / m;
    }

    x[n - 1] = dp[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        x[i] = dp[i] - cp[i] * x[i + 1];
    }
    return x;
}

vector<double> fdmBVP(double a, double b, double ya, double yb, int n)
{
    double h = (b - a) / n;
    int N = n - 1;
    vector<double> A(N), B(N), C(N), D(N);

    for (int k = 0; k < N; k++)
    {
        double x = a + (k + 1) * h;
        A[k] = 1 - h * p(x) / 2.0;
        B[k] = -2 + h * h * q(x);
        C[k] = 1 + h * p(x) / 2.0;
        D[k] = h * h * r(x);
    }
    D[0] -= A[0] * ya;
    D[N - 1] -= C[N - 1] * yb;

    vector<double> interior = thomas(A, B, C, D);

    vector<double> y(n + 1);
    y[0] = ya;
    y[n] = yb;
    for (int k = 0; k < N; k++)
        y[k + 1] = interior[k];
    return y;
}

int main()
{
    int n;
    double a, b, ya, yb;

    cout << "Enter limits a and b: ";
    cin >> a >> b;

    cout << "Enter boundary values ya and yb: ";
    cin >> ya >> yb;

    cout << "Enter number of subintervals: ";
    cin >> n;

    if (n < 2 || n > 100 || b <= a)
    {
        cout << "Invalid input!";
        return 1;
    }

    double h = (b - a) / n;
    vector<double> y = fdmBVP(a, b, ya, yb, n);

    cout << fixed << setprecision(6);
    cout << "\nStep size h = " << h << endl;
    cout << "\ni\t x\t\t y(FDM)\n";
    for (int i = 0; i <= n; i++)
        cout << i << "\t" << a + i * h << "\t" << y[i] << endl;

    return 0;
}
