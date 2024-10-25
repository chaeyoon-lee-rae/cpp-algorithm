#include <iostream>
#include <cstring>
using namespace std;

int n, m, dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 }, a[501][501];
int dp[501][501];


int go(int y, int x) {
    if (y == n - 1 && x == m - 1) return 1;

    int& ret = dp[y][x];
    if (~ret) return ret;

    ret = 0;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] < a[y][x]) {
            ret += go(ny, nx);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    cout << go(0, 0) << "\n";

    return 0;
}
