/*=========================================

▶️ 제목: 백조의 호수
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 40분
▶️ 풀이 참고: Y

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int R, C, ly, lx, wy, wx, dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, cnt;
char a[1504][1504];
queue<pair<int,int>> qSwan, qWater;
bool visitedS[1504][1504], visitedW[1504][1504], flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            cin >> a[i][j];
            if (a[i][j]=='L') ly=i, lx=j, qWater.push({i, j}), visitedW[i][j]=1;
            if (a[i][j]=='.') qWater.push({i,j}), visitedW[i][j]=1; // L 외에도 모든 점은 qWater에 포함해야함
        }
    }

    qSwan.push({ly, lx});
    visitedS[ly][lx]=1;
    while (1) {
        queue<pair<int,int>> qWaterTemp;
        while (qWater.size()) {
            tie(wy, wx) = qWater.front();
            qWater.pop();
            for (int i=0; i<4; ++i) {
                int ny=wy+dy[i];
                int nx=wx+dx[i];
                if (ny<0||ny>=R||nx<0||nx>=C||visitedW[ny][nx]) continue;
                visitedW[ny][nx]=1;
                if (a[ny][nx]=='.') qWater.push({ny,nx});
                if (a[ny][nx]=='X') a[ny][nx]='.', qWaterTemp.push({ny,nx});
            }
        }
        qWater=qWaterTemp;

        queue<pair<int,int>> qSwanTemp;
        while (qSwan.size()) {
            tie(ly, lx) = qSwan.front();
            qSwan.pop();
            for (int i=0; i<4; ++i) {
                int ny=ly+dy[i];
                int nx=lx+dx[i];
                if (ny<0||ny>=R||nx<0||nx>=C||visitedS[ny][nx]) continue;
                visitedS[ny][nx]=1;
                if (a[ny][nx]=='.') qSwan.push({ny,nx});
                if (a[ny][nx]=='X') qSwanTemp.push({ny,nx});
                if (a[ny][nx]=='L') flag=true;
            }
        }
        ++cnt;
        if (flag) {break;}
        qSwan=qSwanTemp;
    }

    cout << cnt << '\n';

    return 0;
}