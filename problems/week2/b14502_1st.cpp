/*=========================================

▶️ 제목: 연구소
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 36분
▶️ 풀이 참고: O

조합을 사용하는 문제라니...
효율적으로 벽을 세울려고 하지말고 일단 무식하게 찾을 수 있는지부터 알아봐야한다!

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, M, a[10][10], b[10][10], y, x, cntone, cnt, ret;
bool visited[10][10];
vector<pair<int,int>> v;
vector<int> vi;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};


int go(int y, int x) {
    visited[y][x] = 1;

    int count = 1;
    for (int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<0||ny>=N||nx<0||nx>=M) continue;
        if (b[ny][nx]==0 && !visited[ny][nx]) count += go(ny, nx);
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> a[i][j];
            if (a[i][j]==0) v.push_back({i,j});
            else if (a[i][j]==1) cntone++;
        }
    }

    for (int i=0; i<v.size(); ++i) {
        for (int j=i+1; j<v.size(); ++j) {
            for (int k=j+1; k<v.size(); ++k) {
                memcpy(b, a, sizeof(a));
                memset(visited, 0, sizeof(visited));    // 제발 다시 reset하는 거 잊지 말자!
                cnt = 0;    // 이것도!

                b[v[i].first][v[i].second] = 1;
                b[v[j].first][v[j].second] = 1;
                b[v[k].first][v[k].second] = 1;

                for (int n=0; n<N; ++n) {
                    for (int m=0; m<M; ++m) {
                        if (b[n][m]==2 && !visited[n][m]) cnt += go(n, m);
                    }
                }

                int cntzero = N*M - (cntone+3) - cnt;
                ret = max(ret, cntzero);
            }
        }
    }

    cout << ret << '\n';

    return 0;
}