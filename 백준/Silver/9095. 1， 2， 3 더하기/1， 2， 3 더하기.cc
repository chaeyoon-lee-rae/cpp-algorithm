#include <iostream>
using namespace std;

int dp[12], t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[0] = 1;
    for (int i = 1; i <= 11; ++i)
        for (int num = 1; num <= 3; ++num) {
            if (i >= num)
                dp[i] += dp[i - num];
        }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}
