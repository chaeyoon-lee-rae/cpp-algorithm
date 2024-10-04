#include <iostream>
using namespace std;

typedef long long ll;
const ll d = ll(1e9);
int n, k;
ll dp[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i <= n; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= k; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= n; ++j)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % d;
    }

    cout << dp[k][n] << "\n";

    return 0;
}
