#include <iostream>
#include <queue>
using namespace std;

int hdy[] = { -2, -1, 1, 2, 2, 1, -1, -2 }, hdx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int k, n, m, dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 }, vis[201][201][31];
bool a[201][201];
queue<pair<pair<int, int>, int>> q;

bool check(int y, int x) {
    return y < 0 || x < 0 || y >= n || x >= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> k;
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    if (a[0][0] == 1) {
        cout << -1 << "\n";
        return 0;
    }

    q.push({ { 0,0 }, 0 });
    vis[0][0][0] = 1;
    while (q.size()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cur_k = q.front().second;
        q.pop();

        if (y == n - 1 && x == m - 1) {
            for (int i = 0; i <= k; ++i) {
                if (vis[y][x][i]) {
                    cout << vis[y][x][i] - 1 << "\n";
                    return 0;
                }
            }
        }

        int ny, nx;
        if (cur_k < k) {
            for (int i = 0; i < 8; ++i) {
                ny = y + hdy[i];
                nx = x + hdx[i];
                if (check(ny, nx) || vis[ny][nx][cur_k+1] || a[ny][nx]) continue;
                vis[ny][nx][cur_k + 1] = vis[y][x][cur_k] + 1;
                q.push({ {ny,nx}, cur_k + 1 });
            }
        }
        for (int i = 0; i < 4; ++i) {
            ny = y + dy[i];
            nx = x + dx[i];
            if (check(ny, nx) || vis[ny][nx][cur_k] || a[ny][nx]) continue;
            vis[ny][nx][cur_k] = vis[y][x][cur_k] + 1;
            q.push({ {ny,nx}, cur_k });
        }
    }

    cout << -1 << "\n";

    return 0;
}
