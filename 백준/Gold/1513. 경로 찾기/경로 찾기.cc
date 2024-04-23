#include <bits/stdc++.h>
using namespace std;  

const int d=1000007;
int a[51][51], dp[51][51][51][51], n, m, c, y, x;

int go(int y, int x, int cnt, int pre) {
    if (y>n||x>m) return 0;
    if (y==n&&x==m) {
        if (cnt==0&&a[y][x]==0) return 1;
        if (cnt==1&&a[y][x]>pre) return 1;
        return 0;
    }
    int &ret=dp[y][x][cnt][pre];
    if (~ret) return ret;
    ret=0;
    if (a[y][x]>pre) {
        ret=(go(y,x+1,cnt-1,a[y][x])+go(y+1,x,cnt-1,a[y][x]))%d;
    } else if (a[y][x]==0) {
        ret=(go(y,x+1,cnt,pre)+go(y+1,x,cnt,pre))%d;
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
        cin >> y >> x;
        a[y][x]=i;
    }
    for (int i=0; i<=c; ++i) {
        cout << go(1,1,i,0) << ' ';
    }

    return 0;
}
