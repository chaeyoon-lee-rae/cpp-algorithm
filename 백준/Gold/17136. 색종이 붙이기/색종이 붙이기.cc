#include <iostream>
using namespace std;

const int n = 10, INF = 1e9;
int ret = INF, p[6];
bool a[11][11];

bool checkSquare(int y, int x, int k) {
    if (y + k > n || x + k > n) return false;
    for (int i = y; i < y + k; ++i)
        for (int j = x; j < x + k; ++j)
            if (a[i][j] == 0) return false;
    return true;
}

void fillSquare(int y, int x, int k, int val) {
    for (int i = y; i < y + k; ++i)
        for (int j = x; j < x + k; ++j)
            a[i][j] = val;
}

void go(int i, int j, int cnt) {
    if (cnt >= ret) return;
    if (j == n) {
        go(i + 1, 0, cnt);
        return;
    }
    if (i == n) {
        ret = min(ret, cnt);
        return;
    }
    if (a[i][j] == 0) {
        go(i, j + 1, cnt);
        return;
    }

    for (int k = 1; k <= 5; ++k) {
        if (checkSquare(i, j, k) && p[k] < 5) {
            fillSquare(i, j, k, 0);
            ++p[k];
            go(i, j + 1, cnt + 1);
            fillSquare(i, j, k, 1);
            --p[k];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    go(0, 0, 0);
    cout << (ret == INF ? -1 : ret) << "\n";

    return 0;
}
