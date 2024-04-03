#include <bits/stdc++.h>
using namespace std;  

const int mx=16, INF=1e9;
int dp[mx][1<<mx], cost[mx][mx], n;

int go(int idx, int num) {
    if (num==(1<<n)-1) {
        return cost[idx][0] ? cost[idx][0] : INF;
    }
    int &ret=dp[idx][num];
    if (~ret) return ret;
    ret=INF;
    for (int i=0; i<n; ++i) {
        if (num & (1<<i)) continue;
        if (cost[idx][i]==0) continue;
        ret=min(ret,go(i, num|(1<<i))+cost[idx][i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> cost[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0,1) << '\n';

    return 0;
}
