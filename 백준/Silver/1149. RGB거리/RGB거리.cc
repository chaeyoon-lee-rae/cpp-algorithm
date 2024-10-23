#include <iostream>
using namespace std;

const int INF = int(1e9);
int n, a[1001][3], dp[1001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = INF; dp[i][1] = INF; dp[i][2] = INF;

        dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i][0]);
        dp[i][0] = min(dp[i][0], dp[i - 1][2] + a[i][0]);

        dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i][1]);
        dp[i][1] = min(dp[i][1], dp[i - 1][2] + a[i][1]);

        dp[i][2] = min(dp[i][2], dp[i - 1][0] + a[i][2]);
        dp[i][2] = min(dp[i][2], dp[i - 1][1] + a[i][2]);
    }

    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << "\n";

    return 0;
}
