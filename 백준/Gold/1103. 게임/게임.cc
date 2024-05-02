#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int dp[51][51], n, m, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
char a[51][51];
bool visited[51][51], flag;
string s;

bool check(int y, int x) {
    return y<0 || x<0 || y>=n || x>=m;
}

int go(int y, int x) {
    if (check(y,x)||a[y][x]=='H') return 0;
    if (visited[y][x]) return INF;
    int &ret=dp[y][x];
    if (ret) return ret;
    
    visited[y][x]=1;
    int val=(int)a[y][x]-'0';
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i]*val;
        int nx=x+dx[i]*val;
        ret=max(ret,go(ny,nx)+1);
    }
    visited[y][x]=0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        cin >> s;
        for (int j=0; j<m; ++j) {
            a[i][j]=s[j];
        }
    }

    int ret=go(0,0);
    cout << (ret>=INF ? -1 : ret) << '\n';

    return 0;
}
