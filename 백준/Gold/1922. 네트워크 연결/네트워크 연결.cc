#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[1001], n, m, ret;
pair<int, int> edge[100001], node[100001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool uni(int a, int b) {
    int A = find(a);
    int B = find(b);

    if (A == B) return false;
    else {
        parent[B] = A;
        return true;
    }
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edge[i] = { c,i };
        node[i] = { a,b };
    }
    sort(edge, edge + m);
    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    for (int i = 0; i < m; ++i) {
        int cost = edge[i].first;
        int idx = edge[i].second;
        if (uni(node[idx].first, node[idx].second))
            ret += cost;
    }
    cout << ret << "\n";

    return 0;
}
