#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

enum direction
{
    EAST = 0,
    SOUTH,
    WEST,
    NORTH
};

struct Dice
{
    int e = 3, w = 4, n = 2, s = 5, top = 1, bot = 6, dir = EAST;

    void changeDir(const int& mapVal) {
        if (bot > mapVal)
            dir = (dir + 1) % 4;
        else if (bot < mapVal)
            dir = (dir - 1 < 0 ? 3 : dir - 1);
    }

    void move() {
        if (dir == EAST) {
            int temp = bot;
            bot = e;
            e = top;
            top = w;
            w = temp;
        }
        else if (dir == SOUTH) {
            int temp = bot;
            bot = s;
            s = top;
            top = n;
            n = temp;
        }
        else if (dir == WEST) {
            int temp = bot;
            bot = w;
            w = top;
            top = e;
            e = temp;
        }
        else { // dir == NORTH
            int temp = bot;
            bot = n;
            n = top;
            top = s;
            s = temp;
        }
    }

} dice;

int n, m, k, ret, a[21][21], dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 }, calc[21][21];
bool vis[21][21];

int dfs(int y, int x, const int& val) {
    vis[y][x] = 1;

    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || vis[ny][nx]) continue;
        if (a[ny][nx] == val)
            cnt += dfs(ny, nx, val);
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    int y = 0, x = 0;
    while (k--) {
        int ny = y + dy[dice.dir];
        int nx = x + dx[dice.dir];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
            dice.dir = (dice.dir + 2) % 4;
            ny = y + dy[dice.dir];
            nx = x + dx[dice.dir];
        }
        dice.move();

        memset(vis, 0, sizeof(vis));
        if (calc[ny][nx]==0)
            calc[ny][nx] = dfs(ny, nx, a[ny][nx]);
        ret += a[ny][nx] * calc[ny][nx];

        dice.changeDir(a[ny][nx]);

        y = ny;
        x = nx;
    }

    cout << ret << "\n";

    return 0;
}
