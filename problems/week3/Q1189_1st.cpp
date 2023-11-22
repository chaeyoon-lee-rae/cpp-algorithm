/*=========================================

▶️ 제목: 컴백홈
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int R, C, K, ret, dy[]={0,-1,0,1}, dx[]={1,0,-1,0};
bool visited[6][6];
char a[6][6];

void go(int y, int x, int count) {
    if (y==0 && x==C-1) {
        if (count==K) ++ret;
        return;
    }
    for (int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<0||nx<0||ny>=R||nx>=C) continue;
        if (!visited[ny][nx]&&a[ny][nx]!='T') {
            visited[ny][nx]=1;
            go(ny, nx, count+1);
            visited[ny][nx]=0;
        }
    }
    return;
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

    visited[R-1][0]=1;
    go(R-1,0,1);

    cout << ret << '\n';    

    return 0;
}