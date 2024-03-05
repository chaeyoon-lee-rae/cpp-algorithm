#include <bits/stdc++.h>
using namespace std;  

int r, c, dy[]={0,1,0,-1}, dx[]={1,0,-1,0}, ret;
bool visChar[27];
char a[21][21];

void dfs(int y, int x, int cnt) {
    ret=max(ret,cnt);
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<0||ny>=r||nx<0||nx>=c) continue;
        if (!visChar[a[ny][nx]-'A']) {
            visChar[a[ny][nx]-'A']=1;
            dfs(ny,nx,cnt+1);
            visChar[a[ny][nx]-'A']=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            char c; cin >> c;
            a[i][j]=c;
        }
    }
    
    visChar[a[0][0]-'A']=1;
    dfs(0,0,1);
    cout << ret << '\n';

    return 0;
}
