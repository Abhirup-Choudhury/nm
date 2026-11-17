#include <bits/stdc++.h>
using namespace std;

int jacobiPoisson(vector<vector<double>> &a, double h, double tol, int maxIter)
{
    int n = a.size() - 1;
    vector<vector<double>> b = a;
    int k = 1, iter = 0;

    while (k != 0 && iter < maxIter)
    {
        k = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                b[i][j] = (a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1] - h * h * 4) / 4.0;
                if (fabs(a[i][j] - b[i][j]) > tol)
                    k = 1;
            }
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
                a[i][j] = b[i][j];
        iter++;
    }
    return k != 0 ? -1 : iter;
}

int main()
{
    int n = 4;
    double h = 0.25;
    double tol = 1e-9;
    vector<vector<double>> a(n + 1, vector<double>(n + 1, 0.0));

    for (int i = 0; i <= n; i++)
    {
        double x = i * h;
        a[i][0] = x * x;
        a[i][n] = x * x + 1;
    }
    for (int j = 0; j <= n; j++)
    {
        double y = j * h;
        a[0][j] = y * y;
        a[n][j] = y * y + 1;
    }

    int iter = jacobiPoisson(a, h, tol, 100);

    if (iter < 0)
    {
        cout << "Didn't converge" << endl;
        return 0;
    }

    cout << "Iterations = " << iter << endl;
    cout << fixed << setprecision(6);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << setw(10) << a[i][j];
        cout << endl;
    }
    return 0;
}
