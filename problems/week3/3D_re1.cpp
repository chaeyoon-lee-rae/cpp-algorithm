/*=========================================

▶️ 제목: 불!
▶️ 풀이 여부: ❌ 
▶️ 풀이 시간: 30분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int R, C, visitedF[1004][1004], visitedJ[1004][1004], dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, y, x;
bool flag;
queue<pair<int,int>> qF, qJ;
char a[1004][1004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&visitedF[0][0], &visitedF[0][0]+1004*1004, INF);  // 불이 하나도 없을 경우를 대비하기 위함

    cin >> R >> C;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            cin >> a[i][j];
            if (a[i][j]=='J') qJ.push({i,j}), visitedJ[i][j]=1;
            if (a[i][j]=='F') qF.push({i,j}), visitedF[i][j]=1;
        }
    }

    while (qF.size()) {
        tie(y,x) = qF.front();
        qF.pop();
        for (int i=0; i<4; ++i) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0||ny>=R||nx<0||nx>=C||visitedF[ny][nx]!=INF) continue;
            if (a[ny][nx]=='.') {
                visitedF[ny][nx] = visitedF[y][x]+1;
                qF.push({ny,nx});
            }
        }
    }

    while (qJ.size()) {
        tie(y,x) = qJ.front();
        qJ.pop();
        if (y==0||x==0||y==R-1||x==C-1) {flag=true; break;}

        for (int i=0; i<4; ++i) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0||ny>=R||nx<0||nx>=C||visitedJ[ny][nx]) continue;
            if (visitedF[ny][nx]<=visitedJ[y][x]+1) continue;
            if (a[ny][nx]=='.') {
                visitedJ[ny][nx] = visitedJ[y][x]+1;
                qJ.push({ny,nx});
            }
        }
    }

    if (flag) cout << visitedJ[y][x] << '\n';
    else cout << "IMPOSSIBLE" << '\n';


    return 0;
}