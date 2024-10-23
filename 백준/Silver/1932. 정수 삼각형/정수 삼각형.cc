#include <iostream>
#include <algorithm>
using namespace std;

int a[501][501], n, dp[501][501], ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            cin >> a[i][j];

    dp[0][0] = a[0][0];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
        }

    for (int i = 0; i < n; ++i)
        ret = max(ret, dp[n][i]);
    cout << ret << "\n";

    return 0;
}
