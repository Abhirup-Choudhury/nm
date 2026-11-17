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

vector<vector<double>> heatBTCS(int N, int M, double alpha, double dt)
{
    double dx = 1.0 / N;
    double r = alpha * dt / (dx * dx);
    vector<vector<double>> u(N + 1, vector<double>(M + 1, 0.0));

    for (int i = 0; i <= N; i++)
    {
        double x = i * dx;
        u[i][0] = x * (1 - x);
    }

    vector<double> a(N - 1, -r), b(N - 1, 1 + 2 * r), c(N - 1, -r), d(N - 1);

    for (int n = 0; n < M; n++)
    {
        u[0][n + 1] = 0;
        u[N][n + 1] = 0;

        for (int i = 1; i < N; i++)
            d[i - 1] = u[i][n];

        vector<double> sol = thomas(a, b, c, d);
        for (int i = 1; i < N; i++)
            u[i][n + 1] = sol[i - 1];
    }
    return u;
}

int main()
{
    int N = 4, M = 10;
    double alpha = 1.0;
    double dt = 0.025;

    vector<vector<double>> u = heatBTCS(N, M, alpha, dt);

    cout << fixed << setprecision(4);
    for (int n = 0; n <= M; n++)
    {
        cout << "Time = " << n * dt << "   ";
        for (int i = 0; i <= N; i++)
            cout << u[i][n] << " ";
        cout << endl;
    }
    return 0;
}
