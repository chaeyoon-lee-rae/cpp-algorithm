#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, a[21], dp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        dp[0] = 1;

        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        cin >> m;

        for (int i = 0; i < n; ++i)
            for (int j = a[i]; j <= m; ++j)
                dp[j] += dp[j - a[i]];

        cout << dp[m] << "\n";
    }

    return 0;
}
