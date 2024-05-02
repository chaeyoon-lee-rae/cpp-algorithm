#include <bits/stdc++.h>
using namespace std;  

const int mod=1000007;
int n, m, c, dp[51][51][51][51], a[51][51];

int go(int y, int x, int cnt, int prev) {
    if (y>=n||x>=m) return 0;
    if (y==n-1&&x==m-1) {
        if (cnt==0&&a[y][x]==0) return 1;
        if (cnt==1&&a[y][x]>prev) return 1;
        return 0;
    }
    int &ret=dp[y][x][cnt][prev];
    if (~ret) return ret;
    ret=0;
    if (a[y][x]==0) {
        ret=(go(y+1, x, cnt, prev)+go(y,x+1,cnt,prev)) % mod;
    } else if (a[y][x]>prev) {
        ret=(go(y+1,x,cnt-1,a[y][x])+go(y,x+1,cnt-1,a[y][x])) % mod;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> c;
    for (int i=1; i<=c; ++i) {
        int y, x;
        cin >> y >> x;
        --y, --x;
        a[y][x]=i;
    }

    for (int i=0; i<=c; ++i) {
        cout << go(0,0,i,0) << ' ';
    }

    return 0;
}
