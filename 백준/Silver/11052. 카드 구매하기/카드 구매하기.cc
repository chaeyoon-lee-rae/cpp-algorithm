#include <iostream>
using namespace std;

int n, p, dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p;
        for (int j = i; j <= n; ++j)
            dp[j] = max(dp[j], dp[j - i] + p);
    }

    cout << dp[n] << "\n";

    return 0;
}
