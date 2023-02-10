#include <iostream>
#include <climits>
using namespace std;
#define oo LONG_MAX

long dp[205][205];
long a[205];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = 0;
    a[n + 1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = -oo;
        }
    }

    for (int o = 0; o < n; o++)
    {
        for (int i = 1; i + o <= n; i++)
        {
            int j = i + o;
            if (o == 0)
            {
                dp[i][j] = a[i - 1] + a[i] + a[j + 1];
                continue;
            }

            dp[i][j] = max(dp[i][j], dp[i + 1][j] + a[i - 1] + a[i] + a[j + 1]);

            dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i - 1] + a[j] + a[j + 1]);

            for (int k = i + 1; k <= j - 1; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + a[i - 1] + a[k] + a[j + 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}