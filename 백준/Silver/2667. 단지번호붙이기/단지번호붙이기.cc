#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int lst[326], n, idx, dy[] = { 0, 1, 0, -1 }, dx[] = { 1, 0, -1, 0 };
bool vis[26][26], a[26][26];
vector<int> v;

int dfs(int y, int x) {
    vis[y][x] = 1;
    int cnt = 1;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (!vis[ny][nx] && a[ny][nx])
            cnt += dfs(ny, nx);
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < n; ++j)
            a[i][j] = str[j] - '0';
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!vis[i][j] && a[i][j])
                lst[idx++] = dfs(i, j);

    sort(lst, lst + idx);
    cout << idx << "\n";
    for (int i = 0; i < idx; ++i)
        cout << lst[i] << "\n";

    return 0;
}
