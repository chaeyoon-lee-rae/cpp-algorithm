#include <bits/stdc++.h>
using namespace std;  

int N, L, R, a[54][54], visited[54][54], cSum, cnt, ret;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
vector<pair<int,int>> v;

int go(int y, int x) {
    int cnt = 1;

    for (int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny<0||ny>=N||nx<0||nx>=N||visited[ny][nx]) continue;
        if (abs(a[ny][nx]-a[y][x])>=L && abs(a[ny][nx]-a[y][x])<=R) {
            cSum += a[ny][nx];
            visited[ny][nx]=1;
            v.push_back({ny, nx});
            cnt += go(ny, nx);
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> a[i][j];
        }
    }

    while (true) {
        bool flag=0;
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (!visited[i][j]) {
                    v.clear();
                    v.push_back({i,j});
                    cSum = a[i][j];
                    visited[i][j]=1;
                    cnt=go(i,j);
                    
                    if (v.size()==1) continue;
                    for (auto it : v) a[it.first][it.second] = cSum/cnt, flag=1;
                }
            }
        }
        if (!flag) break;
        ret++;
    }

    cout << ret << '\n';

    return 0;
}