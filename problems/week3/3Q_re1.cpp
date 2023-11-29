/*=========================================

▶️ 제목: 컴백홈
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 14분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int R, C, K, ret, dy[]={0,-1,0,1}, dx[]={1,0,-1,0};
bool visited[6][6];
char a[6][6];

void go(int y, int x, int cnt) {
    if (cnt>K) return;
    if (y==0&&x==C-1&&cnt==K) {++ret; return;}
    
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<0||ny>=R||nx<0||nx>=C||visited[ny][nx]||a[ny][nx]=='T') continue;
        visited[ny][nx]=1;
        go(ny, nx, cnt+1);
        visited[ny][nx]=0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> K;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            cin >> a[i][j];
        }
    }

    visited[R-1][0]=1;      // BFS, DFS 흔한 실수 -> 출발지점 visited 처리 안해줌
    go(R-1, 0, 1);
    cout << ret << '\n';

    return 0;
}