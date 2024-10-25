#include <iostream>
using namespace std;

int n, m, a[44], ret, dp[44];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= 40; ++i)
        dp[i] = dp[i - 2] + dp[i - 1];

    a[0] = 0;
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    a[m + 1] = n + 1;

    ret = 1;
    for (int i = 1; i <= m + 1; ++i)
        ret *= dp[a[i] - a[i - 1] - 1];

    cout << ret << "\n";

    return 0;
}
