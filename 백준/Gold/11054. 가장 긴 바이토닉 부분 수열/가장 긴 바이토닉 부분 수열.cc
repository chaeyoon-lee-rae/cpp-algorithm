#include <iostream>
using namespace std;

int dp[1001][2], n, a[1001], ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        dp[i][0] = dp[i][1] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i])
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            if (a[j] > a[i])
                dp[i][1] = max(dp[i][1], max(dp[j][0], dp[j][1]) + 1);
        }
        ret = max(ret, dp[i][1]);
    }

    cout << ret << "\n";

    return 0;
}
