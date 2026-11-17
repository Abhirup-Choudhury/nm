#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    vector<vector<double>> A = {
        {2.0, -1.0, 0.0, 0.0},
        {-4.5, 5.0, -1.0, 0.0},
        {0.0, 5.1, 1.5, -3.5},
        {0.0, 0.0, -0.3, -3.2}};

    vector<double> D = {1.5, 0.0, -2.0, 4.0};
    int n = A.size();

    cout << "Matrix A:\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << "[ ";
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << " ]\n";
    }
    cout << "\nMatrix D:\n\n";
    cout << "[ ";
    for (int j = 0; j < n; j++)
    {
        cout << D[j] << " ";
    }
    cout << " ]\n";

    vector<double> a(n, 0.0);
    vector<double> b(n, 0.0);
    vector<double> c(n, 0.0);

    for (int i = 0; i < n; ++i)
    {
        b[i] = A[i][i];
        if (i > 0)
        {
            a[i] = A[i][i - 1];
        }
        if (i < n - 1)
        {
            c[i] = A[i][i + 1];
        }
    }

    vector<double> X = thomas(a, b, c, D);
    cout << "\nSolution Vector X:\n\n";
    cout << fixed << setprecision(4);
    for (int i = 0; i < n; ++i)
    {
        cout << "x" << i + 1 << " : " << X[i] << "\n";
    }
    return 0;
}
