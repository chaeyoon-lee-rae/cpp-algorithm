/*=========================================

▶️ 제목: 알파벳
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 19분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int R, C, dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, ret;
bool visited[27];
char a[21][21];

void go(int y, int x, int cnt) {
    ret = max(ret,cnt);

    for (int i=0; i<4; ++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<0||ny>=R||nx<0||nx>=C||visited[a[ny][nx]-'A']) continue;
        visited[a[ny][nx]-'A']=1;
        go(ny, nx, cnt+1);
        visited[a[ny][nx]-'A']=0;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            cin >> a[i][j];
        }
    }

    visited[a[0][0]-'A']=1;
    go(0,0,1);
    cout << ret << '\n';

    return 0;
}