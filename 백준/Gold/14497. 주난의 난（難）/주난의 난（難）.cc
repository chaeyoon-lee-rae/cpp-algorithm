#include <bits/stdc++.h>
using namespace std;  

int N, M, xx1, yy1, xx2, yy2, visited[304][304], dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, cnt;
char a[304][304];
bool flag;
queue<pair<int,int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> yy1 >> xx1 >> yy2 >> xx2;
    --xx1; --yy1; --xx2; --yy2;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> a[i][j];
        }
    }

    q.push({yy1, xx1});
    visited[yy1][xx1]=1;
    while (1) {
        queue<pair<int,int>> qTemp;
        while (q.size()) {
            int y=0, x=0;
            tie(y,x) = q.front(); q.pop();
            if (y==yy2&&x==xx2) {flag=true; break;}
            for (int i=0; i<4; ++i) {
                int ny=y+dy[i];
                int nx=x+dx[i];
                if (ny<0||ny>=N||nx<0||nx>=M||visited[ny][nx]) continue;
                visited[ny][nx]=visited[y][x]+1;
                if (a[ny][nx]=='0') q.push({ny,nx});
                else a[ny][nx]='0', qTemp.push({ny,nx});
            }
        }
        if (flag==true) break;
        q=qTemp;
        ++cnt;
    }

    cout << cnt << '\n';

    return 0;
}