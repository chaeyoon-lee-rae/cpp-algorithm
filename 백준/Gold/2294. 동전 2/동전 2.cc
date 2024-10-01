#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = static_cast<int>(1e6);
int coin[101], dp[10001], n, k;
bool temp[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x <= k) temp[x] = 1;
    }

    int idx = 0;
    for (int i = 0; i <= k; ++i)
        if (temp[i])
            coin[idx++] = i;

    fill(dp, dp + 10001, INF);
    
    dp[0] = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 0; j < idx; ++j)
            if (coin[j] <= i)
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);

    cout << (dp[k] == INF ? -1 : dp[k]) << "\n";

    return 0;
}
