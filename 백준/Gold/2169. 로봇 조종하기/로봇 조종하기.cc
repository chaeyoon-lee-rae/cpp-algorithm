#include <iostream>
#include <string>
using namespace std;

const int INF = int(1e9);
int dp[1001][1001][3], a[1001][1001], n, m, dy[] = {0, 1, 0}, dx[] = {1, 0, -1};
bool vis[1001][1001];

int go(int y, int x, int dir) {
    if (y == n - 1 && x == m - 1) return a[n - 1][m - 1];

    int& ret = dp[y][x][dir];
    if (ret != -INF) return ret;

    for (int i = 0; i < 3; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx]) continue;
        vis[ny][nx] = 1;
        ret = max(ret, go(ny, nx, i) + a[y][x]);
        vis[ny][nx] = 0;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    fill(&dp[0][0][0], &dp[0][0][0] + 1001 * 1001 * 3, -INF);

    vis[0][0] = 1;
    cout << go(0, 0, 0) << "\n";

    return 0;
}
