#include <iostream>
#include <cstring>
using namespace std;

int n, dp[10001][3], a[10001];

int go(int idx, int cons) {
    if (idx == n) return 0;

    int& ret = dp[idx][cons];
    if (~ret) return ret;

    ret = 0;
    if (cons < 2) 
        ret = max(ret, go(idx + 1, cons + 1) + a[idx]);
    ret = max(ret, go(idx + 1, 0));

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << go(0, 0) << "\n";

    return 0;
}
