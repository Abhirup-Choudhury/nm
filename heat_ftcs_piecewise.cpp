#include <bits/stdc++.h>
using namespace std;

void printLevel(const vector<double> &x, const vector<double> &u)
{
    for (size_t i = 0; i < u.size(); ++i)
        cout << "u(" << x[i] << ") = " << u[i] << '\n';
}

void heatFTCSPiecewise(int N, double dx, double dt, double r, int steps)
{
    vector<double> x(N + 1), u(N + 1), unew(N + 1);

    for (int i = 0; i <= N; ++i)
    {
        x[i] = i * dx;
        if (x[i] <= 0.5)
            u[i] = 2.0 - x[i];
        else
            u[i] = 2.0 * (1.0 - x[i]);
    }
    u[0] = 0.0;
    u[N] = 0.0;

    cout << "\nInitial values:\n";
    printLevel(x, u);

    for (int n = 1; n <= steps; ++n)
    {
        unew[0] = 0.0;
        unew[N] = 0.0;
        for (int i = 1; i < N; ++i)
            unew[i] = u[i] + r * (u[i + 1] - 2.0 * u[i] + u[i - 1]);
        u = unew;

        cout << "\nAt time t = " << n * dt << '\n';
        printLevel(x, u);
    }
}

int main()
{
    double dx = 0.25, dt = 0.0025;
    double c, T;

    cout << "Enter value of c: ";
    cin >> c;
    cout << "Enter final time T: ";
    cin >> T;

    double r = c * c * dt / (dx * dx);

    if (r > 0.5)
    {
        cout << "Stability condition not satisfied!";
        return 0;
    }

    const int N = 4;
    int steps = static_cast<int>(T / dt + 1e-9);

    cout << fixed << setprecision(6);
    heatFTCSPiecewise(N, dx, dt, r, steps);
    return 0;
}
