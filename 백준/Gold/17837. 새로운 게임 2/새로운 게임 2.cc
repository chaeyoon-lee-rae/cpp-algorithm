#include <bits/stdc++.h>
using namespace std;

struct Horse { int y, x, dir; };
Horse h[11];
vector<int> v[13][13];
int n, k, a[13][13], dy[] = {0,0,-1,1}, dx[] = {1,-1,0,0}, turn;
bool flag;

bool out(int y, int x) {
    return (y < 0 || x < 0 || y >= n || x >= n);
}

bool goAndCheck(vector<int>::iterator &pos, int &y, int &x, int &ny, int &nx) {
    for (auto it = pos; it != v[y][x].end(); ++it) {
        v[ny][nx].push_back(*it);
        h[*it].y = ny;
        h[*it].x = nx;
    }
    if (v[ny][nx].size() >= 4) return true;
    v[y][x].erase(pos, v[y][x].end());
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }

    for (int i = 1; i <= k; ++i) {
        int y, x, dir; cin >> y >> x >> dir;
        --y, --x, --dir;
        v[y][x].push_back(i);
        h[i] = { y,x,dir };
    }

    while (turn<=1000) {
        ++turn;
        for (int i = 1; i <= k; ++i) {
            int y = h[i].y, x = h[i].x, &dir = h[i].dir;
            auto pos = find(v[y][x].begin(), v[y][x].end(), i);
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (out(ny,nx)||a[ny][nx] == 2) {
                dir ^= 1;
                ny = y + dy[dir];
                nx = x + dx[dir];
                if (out(ny, nx) || a[ny][nx] == 2) continue;
            }

            if (a[ny][nx] == 1) reverse(pos, v[y][x].end());
            if (goAndCheck(pos, y, x, ny, nx)) {
                flag = true; break;
            }
        }
        if (flag) break;
    }

    cout << (flag ? turn : -1) << '\n';

    return 0;
}
