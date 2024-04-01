#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int t, w, dp[1001][2][31], b[1001];

int go(int sec, int tree, int cnt) {
    if (cnt<0) return -INF;
    if (sec==t) return 0;
    int &ret=dp[sec][tree][cnt];
    if (~ret) return ret;
    return ret=max(go(sec+1,tree^1,cnt-1),go(sec+1,tree,cnt))+(tree==b[sec]-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp,-1,sizeof(dp));
    cin >> t >> w;
    for (int i=0; i<t; ++i) cin >> b[i];
    cout << max(go(0,1,w-1), go(0,0,w)) << '\n';

    return 0;
}
