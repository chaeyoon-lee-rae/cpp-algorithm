#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e9;
int t, w, dp[1001][2][31];
bool tree[1001];

int go(int tr, int cur, int cnt) {
    if (cur < t && cnt > w) return -INF;
    if (cur == t) return 0;

    int& ret = dp[cur][tr][cnt];
    if (~ret) return ret;

    int a = go(tr ^ 1, cur + 1, cnt + 1);
    int b = go(tr, cur + 1, cnt);
    return ret = max(a, b) + (tr == tree[cur]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> t >> w;
    int temp;
    for (int i = 0; i < t; ++i) {
        cin >> temp;
        tree[i] = temp - 1;
    }

    cout << max(go(0, 0, 0), go(1, 0, 1)) << "\n";

    return 0;
}
