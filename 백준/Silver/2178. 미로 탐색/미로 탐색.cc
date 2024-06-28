#include <bits/stdc++.h>
using namespace std;  

int n, m, vis[101][101], y, x, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
bool a[101][101];
string temp;
queue<pair<int,int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        cin >> temp;
        for (int j=0; j<m; ++j) 
            a[i][j]=temp[j]-'0';
    }

    vis[0][0]=1;
    q.push({0,0});
    while(q.size()) {
        tie(y, x)=q.front(); q.pop();
        for (int i=0; i<4; ++i) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0||nx<0||ny>=n||nx>=m||a[ny][nx]==0) continue;
            if (vis[ny][nx]) continue;
            vis[ny][nx]=vis[y][x]+1;
            q.push({ny,nx});
        }
    }
    cout << vis[n-1][m-1] << '\n';


    return 0;
}
