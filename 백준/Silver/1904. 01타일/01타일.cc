#include <iostream>
using namespace std;

const int mod = 15746;
int dp[1000001], n;

int main() {
    cin >> n;

    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }

    cout << dp[n] << "\n";

    return 0;
}
