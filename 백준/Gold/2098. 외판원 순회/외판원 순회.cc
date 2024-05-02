#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9, mx=16;
int dp[mx][1<<mx], w[mx][mx], n;

int go(int visited, int here) {
    if (visited==(1<<n)-1) {
        return w[here][0] ? w[here][0] : INF;
    }
    int &ret=dp[here][visited];
    if (~ret) return ret;
    ret=INF;
    for (int i=0; i<n; ++i) {
        if (visited & (1<<i)) continue;
        if (w[here][i]==0) continue;
        ret=min(ret,go(visited|(1<<i),i)+w[here][i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            scanf("%d", &w[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", go(1,0));

    return 0;
}
