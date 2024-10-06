#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parents[100001], n, m, x, y, c, mx, ret;
pair<int,int> town[1000001], cost[1000001];

int Find(int x) {
    if (x == parents[x]) return x;
    return parents[x] = Find(parents[x]);
}

bool Union(int a, int b) {
    if (Find(a) == Find(b)) 
        return false;

    int A = Find(a);
    int B = Find(b);

    parents[A] = B;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        parents[i] = i;

    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> c;
        town[i] = { x, y };
        cost[i] = { c, i };
    }

    sort(cost, cost + m);

    for (int i = 0; i < m; ++i) {
        c = cost[i].first;
        const int& idx = cost[i].second;

        x = town[idx].first;
        y = town[idx].second;
        if (Union(x, y)) {
            ret += c;
            mx = max(mx, c);
        }
    }

    cout << ret - mx << "\n";
    
    return 0;
}
