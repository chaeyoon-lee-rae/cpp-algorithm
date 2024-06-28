#include <bits/stdc++.h>
using namespace std;  

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int M, N, K, xx1, yy1, xx2, yy2, cnt, area;
bool a[104][104];
bool visited[104][104];
vector<int> v1;

void dfs(int y, int x) {
    visited[y][x] = 1;
    area++;

    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (!a[ny][nx] || visited[ny][nx]) continue;

        dfs(ny, nx);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    vector<pair<int,int>> v[K];
    for (int k=0; k<K; k++) {
        cin >> xx1 >> yy1 >> xx2 >> yy2;
        v[k].push_back({yy1, xx1});
        v[k].push_back({yy2, xx2});
    }

    fill(&a[0][0], &a[0][0] + 104*104, 1);
    for (int k=0; k<K; k++) {
        tie(yy1, xx1) = v[k][0];
        tie(yy2, xx2) = v[k][1];
        for (int i=yy1; i < yy2; i++) {
            for (int j=xx1; j < xx2; j++) {
                a[i][j] = 0;
            }
        }
    }


    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (a[i][j] && !visited[i][j]) {
                area = 0;
                
                dfs(i, j);

                cnt++;
                v1.push_back(area);
            }
        }
    }

    cout << cnt << '\n';

    sort(v1.begin(), v1.end());
    for (int ret : v1) {
        cout << ret << " ";
    }

    return 0;
}