#include <bits/stdc++.h>
using namespace std;

double p(double x) { return 1.0; }
double r(double x) { return 0.0; }
double q(double x) { return 0.0; }
double f(double x) { return 0.0; }

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

vector<double> solveBVP(double a, double b, double alpha, double beta, int n)
{
    double h = (b - a) / n;
    int N = n - 1;
    vector<double> lower(N), diag(N), upper(N), rhs(N);

    for (int k = 0; k < N; k++)
    {
        double xi = a + (k + 1) * h;
        double pi = p(xi), ri = r(xi), qi = q(xi);
        lower[k] = pi / (h * h) - ri / (2 * h);
        diag[k] = -2 * pi / (h * h) + qi;
        upper[k] = pi / (h * h) + ri / (2 * h);
        rhs[k] = f(xi);
    }
    rhs[0] -= lower[0] * alpha;
    rhs[N - 1] -= upper[N - 1] * beta;

    vector<double> interior = thomas(lower, diag, upper, rhs);

    vector<double> y(n + 1);
    y[0] = alpha;
    y[n] = beta;
    for (int k = 0; k < N; k++)
        y[k + 1] = interior[k];
    return y;
}

int main()
{
    int n;
    double a, b, alpha, beta;
    cout << "Enter a and b: ";
    cin >> a >> b;
    cout << "Enter boundary values y(a) and y(b): ";
    cin >> alpha >> beta;
    cout << "Enter number of intervals n: ";
    cin >> n;
    if (n < 2 || b == a)
    {
        cout << "Invalid input.\n";
        return 1;
    }

    vector<double> y = solveBVP(a, b, alpha, beta, n);
    double h = (b - a) / n;

    cout << "\n x\t\t y\n";
    for (int i = 0; i <= n; i++)
        cout << fixed << setprecision(4) << a + i * h << "\t " << setprecision(6) << y[i] << "\n";
    return 0;
}
