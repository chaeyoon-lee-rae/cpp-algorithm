#include <iostream>
using namespace std;

const int mod = int(1e9) + 3;
int dp[1001][501], n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    if (n / 2 < k) {
        cout << 0 << "\n";
        return 0;
    }

    // idx, cnt -> 현재 idx번째까지 cnt개를 고를 경우의 수
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for (int i = 2; i < n; ++i)
        for (int j = 1; j <= k; ++j)
            dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;

    cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % mod << "\n";

    return 0;
}
