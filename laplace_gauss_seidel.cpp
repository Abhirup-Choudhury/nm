#include <bits/stdc++.h>
using namespace std;

void gaussSeidelLaplace(vector<vector<double>> &u, double tol, int maxIter)
{
    int n = u.size(), m = u[0].size();
    for (int iter = 1; iter <= maxIter; iter++)
    {
        double maxDiff = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                double old = u[i][j];
                u[i][j] = 0.25 * (u[i + 1][j] + u[i - 1][j] + u[i][j + 1] + u[i][j - 1]);
                maxDiff = max(maxDiff, fabs(u[i][j] - old));
            }
        }
        if (maxDiff < tol)
        {
            cout << "Converged after " << iter << " iterations.\n";
            break;
        }
    }
}

int main()
{
    int n, m, maxIter;
    double tol;

    cout << "Enter number of grid points in x-direction: ";
    cin >> n;
    cout << "Enter number of grid points in y-direction: ";
    cin >> m;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    vector<vector<double>> u(n, vector<double>(m, 0.0));

    for (int i = 0; i < n; i++)
    {
        u[i][0] = 100;
        u[i][m - 1] = 0;
    }
    for (int j = 0; j < m; j++)
    {
        u[0][j] = 0;
        u[n - 1][j] = 0;
    }

    gaussSeidelLaplace(u, tol, maxIter);

    cout << "\nSolution of Laplace Equation:\n";
    cout << fixed << setprecision(3);
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
            cout << setw(9) << u[i][j];
        cout << "\n";
    }
    return 0;
}
