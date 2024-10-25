#include <iostream>
using namespace std;

int dp[1001][1001], n, m, ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> ch;
            if (ch - '0')
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            ret = max(ret, dp[i][j]);
        }

    cout << ret * ret << "\n";

    return 0;
}
