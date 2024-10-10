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
        --y; --x;
        a[y][x] = i;
    }

    if (a[0][0]) {
        dp[0][0][1][a[0][0]] = 1;
    }
    else {
        dp[0][0][0][0] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j < m-1 && a[i][j + 1]) {
                for (int k = 1; k <= c; ++k) { // cnt
                    for (int p = 0; p < a[i][j + 1]; ++p) { // prev
                        dp[i][j + 1][k][a[i][j + 1]] += dp[i][j][k - 1][p];
                        dp[i][j + 1][k][a[i][j + 1]] %= mod;
                    }
                }
            }
            else {
                for (int k = 0; k <= c; ++k) { // cnt
                    for (int p = 0; p <= c; ++p) { // prev
                        dp[i][j + 1][k][p] += dp[i][j][k][p];
                        dp[i][j + 1][k][p] %= mod;
                    }
                }
            }

            //for (int k = 0; k <= c; ++k) {
            //    for (int i = 0; i < n; ++i) {
            //        for (int j = 0; j < m; ++j) {
            //            int sum = 0;
            //            for (int p = 0; p <= c; ++p) {
            //                sum += dp[i][j][k][p];
            //            }
            //            cout << sum << " ";
            //        }
            //        cout << "\n";
            //    }
            //    cout << "\n";
            //}


            if (i < n-1 && a[i + 1][j]) {
                for (int k = 1; k <= c; ++k) { // cnt
                    for (int p = 0; p < a[i + 1][j]; ++p) { // prev
                        dp[i + 1][j][k][a[i + 1][j]] += dp[i][j][k - 1][p];
                        dp[i + 1][j][k][a[i + 1][j]] %= mod;
                    }
                }
            }
            else {
                for (int k = 0; k <= c; ++k) { // cnt
                    for (int p = 0; p <= c; ++p) { // prev
                        dp[i + 1][j][k][p] += dp[i][j][k][p];
                        dp[i + 1][j][k][p] %= mod;
                    }
                }
            }



            //for (int k = 0; k <= c; ++k) {
            //    for (int i = 0; i < n; ++i) {
            //        for (int j = 0; j < m; ++j) {
            //            int sum = 0;
            //            for (int p = 0; p <= c; ++p) {
            //                sum += dp[i][j][k][p];
            //            }
            //            cout << sum << " ";
            //        }
            //        cout << "\n";
            //    }
            //    cout << "\n";
            //}

        }
    }

    for (int i = 0; i <= c; ++i) {
        int sum = 0;
        for (int j = 0; j <= c; ++j) {
            sum += dp[n - 1][m - 1][i][j];
            sum %= mod;
        }
        cout << sum << " ";
    }

    return 0;
}
