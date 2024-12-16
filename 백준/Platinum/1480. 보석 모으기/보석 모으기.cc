#include <iostream>
#include <cstring>
using namespace std;

int jew[14], bagN, jewN, bagLim, dp[11][1<<14][21];

int go(int idx, int curJew, int curCap) {
    if (idx == bagN) return 0;

    int& ret = dp[idx][curJew][curCap];
    if (~ret) return ret;

    ret = 0;
    for (int i = 0; i < jewN; ++i) {
        if ((1 << i) & curJew) continue;
        if (curCap - jew[i] >= 0)
            ret = max(ret, go(idx, curJew | (1 << i), curCap - jew[i]) + 1);
        else
            ret = max(ret, go(idx + 1, curJew, bagLim));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> jewN >> bagN >> bagLim;
    for (int i = 0; i < jewN; ++i)
        cin >> jew[i];

    memset(dp, -1, sizeof(dp));

    cout << go(0, 0, bagLim) << "\n";

    return 0;
}
