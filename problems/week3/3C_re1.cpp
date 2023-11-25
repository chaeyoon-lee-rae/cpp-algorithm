/*=========================================

▶️ 제목: 인구 이동
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 30분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, L, R, a[54][54], dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, ret, sum, count;
bool visited[54][54];
vector<pair<int,int>> pos;

void dfs(int y, int x) {
    pos.push_back({y,x});
    sum+=a[y][x];
    visited[y][x]=1;
    
    for (int i=0; i<4; ++i) {
        int ny=dy[i]+y;
        int nx=dx[i]+x;
        if (ny<0||ny>=N||nx<0||nx>=N||visited[ny][nx]) continue;
        if (abs(a[ny][nx]-a[y][x])>=L&&abs(a[ny][nx]-a[y][x])<=R) {
            dfs(ny,nx);
        } 
    }

    return;
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

    while (1) {
        bool flag=0;
        memset(visited, 0, sizeof(visited));

        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (!visited[i][j]) {   // 여기 !visited 처리 안해줬어서 틀림
                    pos.clear(); sum=0;
                    dfs(i, j);
                    if (pos.size()<=1) continue;
                    else {
                        sum /= pos.size(); for (auto p:pos) a[p.first][p.second]=sum;
                        flag=1;
                    }
                }
            }
        }
        if (!flag) break;
        ret++;
    }

    cout << ret << '\n';

    return 0;
}