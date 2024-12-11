#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, a[1001][1001], vis[1001][1001][2], dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 };
struct e { int y, x, cnt; };
queue<e> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] - '0';
        }
    }

    q.push({ 0,0,1 });
    vis[0][0][1] = 1;
    while (q.size()) {
        int y = q.front().y;
        int x = q.front().x;
        int c = q.front().cnt;
        q.pop();

        if (y == n - 1 && x == m - 1) {
            cout << vis[y][x][c] << "\n";
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (c == 1) {
                if (a[ny][nx] == 0 && !vis[ny][nx][1]) {
                    vis[ny][nx][1] = vis[y][x][1] + 1;
                    q.push({ ny,nx,1 });
                }
                else if (a[ny][nx] == 1 && !vis[ny][nx][0]) {
                    vis[ny][nx][0] = vis[y][x][1] + 1;
                    q.push({ ny,nx,0 });
                }
            }
            else {
                if (a[ny][nx] == 0 && !vis[ny][nx][0]) {
                    vis[ny][nx][0] = vis[y][x][0] + 1;
                    q.push({ ny,nx,0 });
                }
            }
        }
    }

    cout << -1 << "\n";        

    return 0;
}
