#include <bits/stdc++.h>
using namespace std;  

int a[51][51], room[2501], n, m, mx, vis[51][51], dy[]={0,-1,0,1}, dx[]={-1,0,1,0}, num, ret;

int dfs(int y, int x, int num) {
    int cnt=1;
    vis[y][x]=num;
    for (int i=0; i<4; ++i) {
        if ((a[y][x]&(1<<i))) continue;
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<0||ny>=n||nx<0||nx>=m||vis[ny][nx]) continue;
        cnt+=dfs(ny,nx,num);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (vis[i][j]==0) {
                ++num;
                room[num]=dfs(i,j,num);
                mx = max(mx,room[num]);
            }
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (i+1<n) {
                if (vis[i][j]!=vis[i+1][j]) {
                    ret = max(ret, room[vis[i][j]]+room[vis[i+1][j]]);
                }
            }
            if (j+1<m) {
                if (vis[i][j]!=vis[i][j+1]) {
                    ret = max(ret, room[vis[i][j]]+room[vis[i][j+1]]);
                }
            }
        }
    }

    cout << num << '\n';
    cout << mx << '\n';
    cout << ret << '\n';

    return 0;
}
