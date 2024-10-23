#include <iostream>
using namespace std;

int dp[10001], a[10001], n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    for (int i = 3; i <= n; ++i)
        dp[i] = max(dp[i - 3] + a[i - 1] + a[i], max(dp[i - 2] + a[i], dp[i - 1]));

    cout << dp[n] << "\n";

    return 0;
}
