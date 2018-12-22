#include <iostream>
using namespace std;

//dp排列組合
int dp[2018][2018];
int C(int n, int m)
{
    if (n - m < m) return C(n, n - m);
    if (m == 0) return 1;
    if (m == 1) return n;
    if (dp[n][m] == 0) {
        dp[n][m] = C(n - 1, m) + C(n - 1, m - 1);
    }
    return dp[n][m];
}

//迴圈排列組合
int NchooseM(int n, int m)
{
    if (n - m < m) m = n - m;
    if (m == 0) return 1;

    int result = 1;
    for (int i = 1; i <= m; i++) {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}
