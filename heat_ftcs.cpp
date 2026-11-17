#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> heatFTCS(int N, int M, double r)
{
    double dx = 1.0 / N;
    vector<vector<double>> u(N + 1, vector<double>(M + 1, 0.0));

    for (int i = 0; i <= N; i++)
    {
        double x = i * dx;
        u[i][0] = x * (1 - x);
    }

    for (int n = 0; n < M; n++)
    {
        u[0][n + 1] = 0;
        u[N][n + 1] = 0;
        for (int i = 1; i < N; i++)
            u[i][n + 1] = u[i][n] + r * (u[i - 1][n] - 2 * u[i][n] + u[i + 1][n]);
    }
    return u;
}

int main()
{
    int N = 4, M = 10;
    double alpha = 1.0;
    double dx = 1.0 / N;
    double dt = 0.025;
    double r = alpha * dt / (dx * dx);

    if (r > 0.5)
    {
        cout << "Unstable";
        return 0;
    }

    vector<vector<double>> u = heatFTCS(N, M, r);

    cout << fixed << setprecision(4);
    cout << "Time";
    for (int i = 0; i <= N; i++)
        cout << setw(10) << i * dx;
    cout << endl;

    for (int n = 0; n <= M; n++)
    {
        cout << setw(5) << n * dt;
        for (int i = 0; i <= N; i++)
            cout << setw(10) << u[i][n];
        cout << endl;
    }
    return 0;
}
