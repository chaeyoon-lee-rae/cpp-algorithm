#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char a[101][101];
bool vis[101][101];
int n, retC, retNC, dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 };

void dfs(int y, int x, const char& color) {
    vis[y][x] = 1;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || vis[ny][nx]) continue;
        if (a[ny][nx] == color)
            dfs(ny, nx, color);
    }
}

void dfsNC(int y, int x, const char& color) {
    vis[y][x] = 1;

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || vis[ny][nx]) continue;
        if ((a[ny][nx] != 'B' && color != 'B') || (a[ny][nx] == 'B' && color == 'B'))
            dfsNC(ny, nx, color);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!vis[i][j]) {
                dfs(i, j, a[i][j]);
                ++retC;
            }

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!vis[i][j]) {
                dfsNC(i, j, a[i][j]);
                ++retNC;
            }

    cout << retC << " " << retNC << "\n";


    return 0;
}
