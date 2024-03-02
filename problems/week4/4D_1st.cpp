/*=========================================

▶️ 제목: 동전 뒤집기
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 30분
▶️ 풀이 참고: △

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int R, C, vis, y, x, dy[]={0, -1, 0, 1}, dx[]={1, 0, -1, 0}, a[21][21], ret;
queue<pair<int,int>> q;

void dfs(int y, int x, int cnt) {
    ret = max(ret, cnt);

    for (int i=0; i<4; ++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<0||ny>=R||nx<0||nx>=C) continue;
        if (!(vis & (1<<a[ny][nx]))) {
            vis |= (1<<a[ny][nx]);
            dfs(ny,nx,cnt+1);
            vis &= ~(1<<a[ny][nx]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            char temp;
            cin >> temp;
            a[i][j]=temp-'A';
        }
    }

    vis |= (1<<a[0][0]);
    dfs(0,0,1);
    cout << ret << '\n';

    return 0;
}