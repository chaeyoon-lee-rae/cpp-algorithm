#include <iostream>
#include <cstring>
using namespace std;

const int INF = int(1e9);
int dp[1001][31][2], t, w;
bool tree[1001];

int go(int idx, int cnt, bool cur) {
    if (cnt > w) return -INF;
    if (idx == t) return 0;

    int& ret = dp[idx][cnt][cur];
    if (~ret) return ret;

    ret = 0;
    ret = max(ret, max(go(idx + 1, cnt, cur), go(idx + 1, cnt + 1, cur ^ 1)) + (tree[idx] == cur));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> t >> w;
    int temp;
    for (int i = 0; i < t; ++i) {
        cin >> temp;
        tree[i] = temp - 1;
    }

    cout << max(go(0, 0, 0), go(0, 1, 1)) << "\n";

    return 0;
}
