#include <iostream>
#include <vector>
using namespace std;

const int INF = int(1e9);
int n, m, a[9][9], ret = INF, dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 };
vector<int> cam[6];
vector<pair<int, int>> pos;

int calc() {
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == 0)
                ++cnt;
    return cnt;
}

void draw(int y, int x, const int& i, const int& val, vector<pair<int,int>>& vp) {
    if (y < 0 || x < 0 || y >= n || x >= m) return;
    if (a[y][x] == 6) return;
    if (a[y][x] == 0) {
        a[y][x] = val;
        vp.push_back({ y, x });
    }
    draw(y + dy[i], x + dx[i], i, val, vp);
}

void go(int idx) {
    if (idx == pos.size()) {
        ret = min(ret, calc());
        return;
    }

    const int& y = pos[idx].first;
    const int& x = pos[idx].second;
    for (auto dir : cam[a[y][x]]) {
        vector<pair<int, int>> vp;
        for (int j = 0; j < 4; ++j)
            if ((1 << j) & dir)
                draw(y + dy[j], x + dx[j], j, 9, vp);

        go(idx + 1);
        for (const auto& it : vp)
            a[it.first][it.second] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] > 0 && a[i][j] < 5)
                pos.push_back({ i,j });

        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            if (a[i][j] == 5) {
                vector<pair<int, int>> temp;
                for (int k = 0; k < 4; ++k)
                    draw(i + dy[k], j + dx[k], k, 9, temp);
            }
    }

    cam[1].push_back(1 << 0);
    cam[1].push_back(1 << 1);
    cam[1].push_back(1 << 2);
    cam[1].push_back(1 << 3);

    cam[2].push_back(1 << 0 | 1 << 2);
    cam[2].push_back(1 << 1 | 1 << 3);

    cam[3].push_back(1 << 0 | 1 << 1);
    cam[3].push_back((1 << 0 | 1 << 1) << 1);
    cam[3].push_back((1 << 0 | 1 << 1) << 2);
    cam[3].push_back(1 << 0 | 1 << 3);

    cam[4].push_back(((1 << 4) - 1) & ~(1 << 0));
    cam[4].push_back(((1 << 4) - 1) & ~(1 << 1));
    cam[4].push_back(((1 << 4) - 1) & ~(1 << 2));
    cam[4].push_back(((1 << 4) - 1) & ~(1 << 3));

    go(0);
    cout << ret << "\n";

    return 0;
}
