#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e9;
int t, w, dp[1001][31][2];
bool tree[1001];

int go(int idx, int cnt, bool cur) {
    if (cnt < 0) return -INF;
    if (idx == t) return 0;

    int& ret = dp[idx][cnt][cur];
    if (~ret) return ret;

    ret = 0;
    int a = go(idx + 1, cnt, cur);
    int b = go(idx, cnt-1, cur^1);
    return ret = max(ret, max(a, b) + (tree[idx] == cur ? 1 : 0));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> w;
    int temp;
    for (int i = 0; i < t; ++i) {
        cin >> temp;
        tree[i] = temp - 1;
    }

    memset(dp, -1, sizeof(dp));
    cout << max(go(0, w, 0), go(0, w - 1, 1)) << "\n";

    return 0;
}
