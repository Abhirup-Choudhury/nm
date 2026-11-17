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

vector<vector<double>> waveCrankNicolson(int N, int M, double h, double k, double c)
{
    double pi = acos(-1.0);
    vector<vector<double>> u(N + 1, vector<double>(M + 1, 0.0));

    for (int i = 0; i <= N; i++)
    {
        double x = h * i;
        u[i][0] = sin(pi * x);
    }
    for (int j = 0; j <= M; j++)
    {
        u[0][j] = 0;
        u[N][j] = 0;
    }

    double r = (k * c) / h;
    double w = (r * r) / 2.0;

    vector<double> A(N - 1, -w), B(N - 1, 1 + 2 * w), C(N - 1, -w), D(N - 1);

    for (int j = 0; j < M; j++)
    {
        for (int i = 1; i < N; i++)
        {
            if (j == 0)
                D[i - 1] = u[i][0];
            else
                D[i - 1] = 2 * u[i][j] - u[i][j - 1] + w * (u[i - 1][j - 1] - 2 * u[i][j - 1] + u[i + 1][j - 1]);
        }

        vector<double> sol = thomas(A, B, C, D);
        for (int i = 1; i < N; i++)
            u[i][j + 1] = sol[i - 1];
    }
    return u;
}

int main()
{
    int N = 4;
    int M = 10;
    double h = 0.25;
    double k = 0.1;
    double c = 1.0;

    vector<vector<double>> u = waveCrankNicolson(N, M, h, k, c);

    cout << fixed << setprecision(6);
    cout << "Space/Time";
    for (int j = 0; j <= M; j++)
        cout << "\t" << j;
    cout << "\n";

    for (int i = 0; i <= N; i++)
    {
        cout << i * h;
        for (int j = 0; j <= M; j++)
            cout << "\t" << u[i][j];
        cout << "\n";
    }
    return 0;
}
