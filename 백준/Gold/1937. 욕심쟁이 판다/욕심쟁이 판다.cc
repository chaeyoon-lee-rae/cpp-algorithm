#include <iostream>
#include <cstring>
using namespace std;

int dp[501][501];
int a[501][501], dy[] = { 0, -1, 0, 1 }, dx[] = { 1, 0, -1, 0 }, n, ret;

int go(int y, int x) {
    int& ret = dp[y][x];
    if (~ret) return ret;

    ret = 0;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (a[y][x] >= a[ny][nx]) continue;

        ret = max(ret, go(ny, nx) + 1);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ret = max(ret, go(i, j) + 1);

    cout << ret << "\n";

    return 0;
}
