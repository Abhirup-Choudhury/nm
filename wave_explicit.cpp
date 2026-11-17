#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> waveExplicit(int N, int M, double c, double dt)
{
    double dx = 1.0 / N;
    double r = c * dt / dx;
    vector<vector<double>> u(N + 1, vector<double>(M + 1, 0.0));

    for (int i = 0; i <= N; i++)
    {
        double x = i * dx;
        u[i][0] = sin(3.14159265 * x);
    }

    for (int i = 1; i < N; i++)
        u[i][1] = u[i][0] + 0.5 * r * r * (u[i - 1][0] - 2 * u[i][0] + u[i + 1][0]);
    u[0][1] = 0;
    u[N][1] = 0;

    for (int n = 1; n < M; n++)
    {
        u[0][n + 1] = 0;
        u[N][n + 1] = 0;
        for (int i = 1; i < N; i++)
            u[i][n + 1] = 2 * u[i][n] - u[i][n - 1] + r * r * (u[i + 1][n] - 2 * u[i][n] + u[i - 1][n]);
    }
    return u;
}

int main()
{
    int N = 4, M = 10;
    double c = 1.0;
    double dt = 0.025;

    vector<vector<double>> u = waveExplicit(N, M, c, dt);

    cout << fixed << setprecision(4);
    for (int n = 0; n <= M; n++)
    {
        cout << "t = " << n * dt << " : ";
        for (int i = 0; i <= N; i++)
            cout << u[i][n] << " ";
        cout << endl;
    }
    return 0;
}
