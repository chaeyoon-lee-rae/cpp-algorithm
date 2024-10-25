#include <iostream>
using namespace std;

const int mod = 10007;
int dp[1001][11], n, ret;

int main() {
    cin >> n;

    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= 10; ++j)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;

    for (int i = 1; i <= 10; ++i)
        ret = (ret + dp[n][i]) % mod;
    cout << ret << "\n";

    return 0;
}
