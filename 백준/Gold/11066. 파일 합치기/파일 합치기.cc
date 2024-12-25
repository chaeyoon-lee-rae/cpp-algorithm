#include <iostream>
using namespace std;

const int INF = int(1e9);
int dp[501][501], pSum[501], n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    while (n--) {
        cin >> k;
        int temp;
        for (int i = 1; i <= k; ++i) {
            cin >> temp;
            pSum[i] = pSum[i - 1] + temp;
        }

        fill(&dp[0][0], &dp[0][0] + 501 * 501, INF);
        for (int i = 1; i <= k; ++i)
            dp[i][i] = 0;
        for (int len = 1; len < k; ++len) {
            for (int s = 1; s + len <= k; ++s) {
                for (int mid = s; mid < s + len; ++mid) {
                    dp[s][s + len] = min(dp[s][s + len], dp[s][mid] + dp[mid + 1][s + len] + pSum[s + len] - pSum[s - 1]);
                }
            }
        }
        cout << dp[1][k] << "\n";
    }

    return 0;
}
