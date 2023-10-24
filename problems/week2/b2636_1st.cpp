/*=========================================

▶️ 제목: 치즈
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

connected components 사용해서 풀어야하는 건 알았다만
바깥 공기부분을 탐색해 나가는 동시에 녹는 치즈 부분들을 저장할 수 있다는 것을 미처 깨닫지 못하였다
그래서 굳이 맵 하나를 더 만들어서 바깥 공기부분을 따로 표시하고 치즈 부분을 다시 탐색하면서 녹는 부분을 변환시켜주었다.
그래도 일단은 쏠..

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, M, a[104][104], b[104][104], hours, cnt;
bool visited[104][104];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

void fillOuter(int y, int x) {
    b[y][x] = 1;
    visited[y][x] = 1;
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (a[ny][nx]==0 && !visited[ny][nx]) {
            fillOuter(ny, nx);
        }
    }
    return;
}

int go(int y, int x) {
    int count = 1;
    visited[y][x] = 1;
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (b[ny][nx]) a[y][x] = 0;
        if (a[ny][nx] && !visited[ny][nx]) count += go(ny,nx);
    }

    return count;
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
        memset(b, 0, sizeof(b));
        memset(visited, 0, sizeof(visited));
        fillOuter(0, 0);

        memset(visited, 0, sizeof(visited));
        int count = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (a[i][j] && !visited[i][j]) count += go(i, j);
            }
        }

        if (count == 0) break;
        hours++; cnt = count;
    }

    cout << hours << '\n';
    cout << cnt << '\n';

    return 0;
}