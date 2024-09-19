#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, retDist, node;
vector<pair<int, int>> nodes[100001];
bool vis[100001];

void go(int here, int dist) {
    vis[here] = 1;

    for (const auto& it : nodes[here])
        if (!vis[it.second])
            go(it.second, dist + it.first);

    if (retDist < dist) {
        node = here;
        retDist = dist;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int idx, a, b;
    for (int i = 0; i < n; ++i) {
        cin >> idx;
        while (true) {
            cin >> a;
            if (a == -1) break;
            cin >> b;
            nodes[idx].push_back({ b, a }); // 거리, 노드
        }
    }

    go(1, 0);
    memset(vis, 0, sizeof(vis));
    go(node, 0);
    cout << retDist << "\n";

    return 0;
}
