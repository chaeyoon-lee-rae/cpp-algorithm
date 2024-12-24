#include <iostream>
using namespace std;

typedef long long ll;
ll dp[10001], n;
const ll mod = 987654321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    dp[0] = dp[2] = 1;

    for (int i = 4; i <= n; i += 2)
        for (int j = 0; j <= i - 2; j += 2) {
            dp[i] += (dp[j] * dp[i - j - 2]);
            dp[i] %= mod;
        }

    cout << dp[n] << "\n";

    return 0;
}
