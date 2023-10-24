/*=========================================

▶️ 제목: 치즈
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

치즈를 녹이는 부분의 x,y 좌표를 큐에 푸쉬하고 나중에 큐의 모든 요소를 순회하여 해당 좌표를 0으로 만드는 방법이다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, M, a[104][104], hour, cnt;
bool visited[104][104];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
queue<pair<int,int>> q;

void go(int y, int x) {
    visited[y][x] = 1;
    if (a[y][x]==1) {q.push({y,x}); return;}
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx > M) continue;
        if (!visited[ny][nx]) go(ny, nx);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        memset(visited, 0, sizeof(visited));
        go(0, 0);
        
        if (q.empty()) break;

        hour++;
        cnt = q.size();     // 마지막 남는 치즈 조각들이 차지하는 칸 수

        while (q.size()) {
            auto it = q.front();
            a[it.first][it.second] = 0;
            q.pop();
        }

    }

    cout << hour << '\n';
    cout << cnt << '\n';

    return 0;
}