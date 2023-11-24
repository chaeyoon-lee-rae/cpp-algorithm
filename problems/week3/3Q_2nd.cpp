/*=========================================

▶️ 제목: 컴백홈
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: O

- go 함수 기저 사례에 1 또는 0을 반환하고 최종적으로 경우의 수를 다 더해줘 반환한다
- BFS처럼 visited에 최단거리를 입력한다

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int R, C, K, dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, visited[6][6];
char a[6][6];

int go(int y, int x) {
    if (y==0 && x==C-1) {
        if (visited[y][x]==K) return 1;
        return 0;
    }
    int ret=0;
    for (int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<0||nx<0||ny>=R||nx>=C) continue;
        if (!visited[ny][nx]&&a[ny][nx]!='T') {
            visited[ny][nx]=visited[y][x]+1;
            ret+=go(ny, nx);
            visited[ny][nx]=0;
        }
    }
    return ret;
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
    cout << go(R-1,0) << '\n';    

    return 0;
}