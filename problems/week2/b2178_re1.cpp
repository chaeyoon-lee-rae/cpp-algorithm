/*=========================================

▶️ 제목: 미로 탐색
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 25분
▶️ 풀이 참고: X

ASCII 값을 사용하여 char를 int 값으로 변환해준다.

=========================================*/


#include <bits/stdc++.h>
using namespace std;  

string s;
const int len = 104;
int N, M;
bool a[len][len];
int visited[len][len];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int,int>> q;


void bfs(int y, int x) {
    q.push({y, x});
    visited[y][x] = 1;
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (!a[ny][nx] || visited[ny][nx]) continue;

            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> s;
        for (int j=0; j<M; j++) {
            a[i][j] = s[j] - '0';   // 1과 0을 int로 저장하기 위함 (ASCII integer value subtraction)
        }
    }

    bfs(0, 0);

    cout << visited[N-1][M-1] << '\n';

    return 0;
}