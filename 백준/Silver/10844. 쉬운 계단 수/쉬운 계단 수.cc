#include <iostream>
using namespace std;

const int d = int(1e9);
int n, dp[101][11], ret;

int main() {
    cin >> n;

    for (int i = 1; i <= 9; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j < 9)
                dp[i][j] += dp[i - 1][j + 1];
            if (j > 0)
                dp[i][j] += dp[i - 1][j - 1];

            dp[i][j] %= d;
        }
    }

    for (int i = 0; i <= 9; ++i)
        ret = (ret + dp[n][i]) % d;

    cout << ret << "\n";

    return 0;
}
