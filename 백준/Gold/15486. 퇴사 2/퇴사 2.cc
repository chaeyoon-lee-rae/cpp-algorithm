#include <iostream>
#include <algorithm>
using namespace std;

int dp[1500004], n, t, p, ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t >> p;
        if (i + t <= n)
            dp[i + t] = max(dp[i + t], dp[i] + p);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[n] << "\n";

    return 0;
}
