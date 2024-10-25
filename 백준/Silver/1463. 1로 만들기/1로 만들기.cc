#include <iostream>
using namespace std;

const int INF = int(1e9);
int n, dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    fill(dp, dp + 1000001, INF);
    dp[n] = 0;
    for (int i = n; i >= 1; --i) {
        if (i % 3 == 0) 
            dp[i / 3] = min(dp[i / 3], dp[i] + 1);
        if (i % 2 == 0) 
            dp[i / 2] = min(dp[i / 2], dp[i] + 1);
        dp[i - 1] = min(dp[i - 1], dp[i] + 1);
    }

    cout << dp[1] << "\n";

    return 0;
}
