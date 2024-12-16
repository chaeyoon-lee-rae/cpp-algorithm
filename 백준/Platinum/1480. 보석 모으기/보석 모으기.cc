#include <iostream>
#include <cstring>
using namespace std;

int jew[14], bagN, jewN, bagLim, dp[11][1<<14];

int check(int jewTemp) {
    int cnt = 0, sum = 0;
    for (int j = 0; j < jewN; ++j)
        if ((1 << j) & jewTemp) {
            ++cnt, sum += jew[j];
            if (sum > bagLim) return 0;
        }
    return cnt;
}

int go(int idx, int curJew) {
    if (idx == bagN) return 0;

    int& ret = dp[idx][curJew];
    if (~ret) return ret;

    ret = 0;
    for (int i = 1; i < (1 << jewN); ++i) {
        if (i & curJew) continue;
        int c = check(i);
        if (c) 
            ret = max(ret, go(idx + 1, i | curJew) + c);
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

    cout << go(0, 0) << "\n";

    return 0;
}
