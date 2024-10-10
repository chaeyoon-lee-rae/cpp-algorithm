#include <iostream>
using namespace std;

const int mod = 1000007;
int a[51][51], dp[51][51][51][51], n, m, c, x, y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> c;
    for (int i = 1; i <= c; ++i) {
        cin >> y >> x;
        a[y][x] = i;
    }

    if (a[1][1])
        dp[1][1][1][a[1][1]] = 1;
    else
        dp[1][1][0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j])
                for (int p = 0; p < a[i][j]; ++p) // prev
                    for (int k = 0; k <= p; ++k) { // cnt
                        dp[i][j][k + 1][a[i][j]] += dp[i][j - 1][k][p] + dp[i - 1][j][k][p];
                        dp[i][j][k + 1][a[i][j]] %= mod;
                    }
            else
                for (int p = 0; p <= c; ++p) // prev
                    for (int k = 0; k <= p; ++k) { // cnt
                        dp[i][j][k][p] += dp[i][j - 1][k][p] + dp[i - 1][j][k][p];
                        dp[i][j][k][p] %= mod;
                    }
        }
    }

    for (int i = 0; i <= c; ++i) {
        int sum = 0;
        for (int j = 0; j <= c; ++j) {
            sum += dp[n][m][i][j];
            sum %= mod;
        }
        cout << sum << " ";
    }

    return 0;
}
