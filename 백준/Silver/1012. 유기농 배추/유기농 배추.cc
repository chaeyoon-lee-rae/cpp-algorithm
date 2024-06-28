#include <bits/stdc++.h>
using namespace std;  

int n, m, k, t, y, x, dy[]={0,1,0,-1}, dx[]={1,0,-1,0}, cnt;
bool a[51][51], vis[51][51];

void dfs(int y, int x) {
    vis[y][x]=1;
    for (int i=0; i<4; ++i) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if (ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==0) continue;
        if (vis[ny][nx]) continue;
        dfs(ny,nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cnt=0; memset(vis,0,sizeof(vis)); memset(a,0,sizeof(a)); 
        cin >> m >> n >> k;
        for (int i=0; i<k; ++i) {
            cin >> x >> y;
            a[y][x]=1;
        }

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (!vis[i][j]&&a[i][j]==1) 
                    dfs(i,j), ++cnt;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
