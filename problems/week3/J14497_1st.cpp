/*=========================================

▶️ 제목: 주난의 난
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 40분
▶️ 풀이 참고: X

치즈문제(2636)가 생각나서 같은 방식인 dfs로 풀었다만
생각보다 사용된 메모리와 시간이 다른 풀이보다 크게 나와서 뭐가 문제일까 생각했다.
선생님 풀이는 bfs를 사용하게 되는데, 한 레벨에서 다시금 1을 탐색해 나가는 방식이다.
나는 같은 자리(주난이 위치)에서 계속 dfs로 connected components를 탐색해 나가는 방식이라서 그런지
같은 범위를 중복해서 탐색하는 시간때문에 그럴 수도 있겠다 생각된다.

그렇다면 치즈문제도 bfs로 풀 수 있다는 것인가? 나중에 한번 시도해봐야겠다.

=========================================*/


#include <bits/stdc++.h>
using namespace std;  

int N, M, xx1, yy1, xx2, yy2, dy[]={0, -1, 0, 1}, dx[]={1, 0, -1, 0}, cnt;
char c[304][304];
bool visited[304][304], flag;


void dfs(int y, int x) {
    visited[y][x] = 1;
    
    for (int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<0||ny>=N||nx<0||nx>=M||visited[ny][nx]) continue;
        if (c[ny][nx]=='1') {c[ny][nx]='0'; visited[ny][nx]=1; continue;}
        if (c[ny][nx]=='0') dfs(ny,nx);
        if (c[ny][nx]=='#') {flag=true; return;}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> yy1 >> xx1 >> yy2 >> xx2;
    --yy1; --xx1; --yy2; --xx2;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> c[i][j];
        }
    }

    while (true) {
        memset(visited, 0, sizeof(visited));
        dfs(yy1, xx1);
        cnt++;
        if (flag) break;
    }

    cout << cnt << '\n';

    return 0;
}