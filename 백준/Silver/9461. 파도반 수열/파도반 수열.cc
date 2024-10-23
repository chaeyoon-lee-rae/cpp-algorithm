#include <iostream>
using namespace std;

int t, num;
long long dp[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    for (int i = 4; i <= 100; ++i)
        dp[i] = dp[i - 3] + dp[i - 2];

    cin >> t;
    while (t--) {
        cin >> num;
        cout << dp[num] << "\n";
    }

    return 0;
}
