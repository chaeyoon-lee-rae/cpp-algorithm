#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct pos { int y, x, emp; };
queue<pos> q;
int n, m, a[301][301], dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 }, t;
bool vis[301][301], flag;

void dfs(int y, int x) {
    vis[y][x] = 1;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (!vis[ny][nx] && a[ny][nx])
            dfs(ny, nx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    while (true) {
        memset(vis, 0, sizeof(vis));
        ++t;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j]) {
                    int cnt = 0;
                    for (int k = 0; k < 4; ++k) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        if (a[ny][nx] == 0) ++cnt;
                    }
                    if (cnt) 
                        q.push({ i, j, cnt });
                }
            }
        }

        if (q.empty()) break;

        while (q.size()) {
            auto p = q.front();
            q.pop();

            a[p.y][p.x] = max(0, a[p.y][p.x] - p.emp);
        }

        flag = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && a[i][j]) {
                    if (!flag) {
                        dfs(i, j);
                        flag = true;
                    }
                    else {
                        cout << t << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << 0 << "\n";

    return 0;
}
