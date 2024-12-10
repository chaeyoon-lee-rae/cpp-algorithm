#include <iostream>
using namespace std;

int a[201], dp[201], ret, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    fill(dp, dp + n, 1);
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < i; ++j)
        if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            ret = max(ret, dp[i]);
        }

    cout << n - ret << "\n";

    return 0;
}
