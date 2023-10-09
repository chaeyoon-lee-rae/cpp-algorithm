#include <bits/stdc++.h>
using namespace std;  

int N, h, cnt, max_cnt;
int a[104][104];
bool visited[104][104];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x) {
    visited[y][x] = 1;

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (visited[ny][nx] || a[ny][nx] <= h) continue;

        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i< N; i++) {
        for (int j=0; j< N; j++) {
            cin >> a[i][j];
        }
    }

    for (int k=0; k<=100; k++) {
        h = k;

        cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (a[i][j] > h && !visited[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        if (max_cnt < cnt) max_cnt = cnt;
    }

    cout << max_cnt << '\n';

    return 0;
}
