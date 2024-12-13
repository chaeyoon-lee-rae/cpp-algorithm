#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[5][5][100001], ret = INF;

int calc(int cur, int nxt) {
    if (cur == nxt) return 1;
    else if (cur == 0) return 2;
    else if (abs(cur - nxt) == 2) return 4;
    else return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dp[0][0][0], &dp[0][0][0] + 5 * 5 * 100001, INF);
    dp[0][0][0] = 0;
    int idx = 0, num;
    while (true) {
        cin >> num;
        if (num == 0) break;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                dp[i][num][idx + 1] = min(dp[i][num][idx + 1], dp[i][j][idx] + calc(j, num));
                dp[num][j][idx + 1] = min(dp[num][j][idx + 1], dp[i][j][idx] + calc(i, num));
            }
        }
        ++idx;
    }

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            ret = min(ret, dp[i][j][idx]);

    cout << ret << "\n";

    return 0;
}
