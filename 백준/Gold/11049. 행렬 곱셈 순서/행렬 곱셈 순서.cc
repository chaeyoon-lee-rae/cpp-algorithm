#include <iostream>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
int n, dp[501][501];
pair<int, int> mat[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> mat[i].first;
        cin >> mat[i].second;
    }

    for (int d = 1; d < n; ++d)
        for (int i = 1; i + d <= n; ++i) {
            dp[i][i + d] = INF;
            for (int j = i; j < i + d; ++j)
                dp[i][i + d] = min(dp[i][i + d], dp[i][j] + dp[j + 1][i + d] 
                                                 + mat[i].first * mat[j].second * mat[i + d].second);
        }

    cout << dp[1][n] << "\n";

    return 0;
}
