#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int LIM = 1000;
int t, n, x[101], y[101], startx, starty, targx, targy;
bool vis[101];

bool bfs() {
    queue<pair<int, int>> q;
    q.push({ startx, starty });
    while (q.size()) {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();

        if ((abs(targx - nx) + abs(targy - ny)) <= LIM)
            return true;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            if ((abs(x[i] - nx) + abs(y[i] - ny)) <= LIM) {
                q.push({ x[i],y[i] });
                vis[i] = true;
            }
        }
    }
    return false;
}

int main() {

    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));

        cin >> n;
        cin >> startx >> starty;
        for (int i = 0; i < n; ++i)
            cin >> x[i] >> y[i];
        cin >> targx >> targy;

        if (bfs()) cout << "happy" << "\n";
        else cout << "sad" << "\n";
    }

    return 0;
}
