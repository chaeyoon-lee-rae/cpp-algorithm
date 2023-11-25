/*=========================================

▶️ 제목: 백조의 호수
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 50분
▶️ 풀이 참고: X

백조와 물 모두 flood fill 방식을 적용하여 총 queue가 4개가 필요하다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int R, C, lx, ly, dy[]={0, -1, 0, 1}, dx[]={1,0,-1,0}, x, y, cnt;
char a[1504][1504];
bool visited[1504][1504], visitedSwan[1504][1504], flag;
queue<pair<int,int>> waterQ, qSwan;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i=0; i<R; ++i) {
        string s;
        cin >> s;
        for (int j=0; j<C; ++j) {
            a[i][j] = s[j];
            // 처음에 L을 포함시키지 않아서 실패하였다, 백조 주변에도 얼음이 녹아야한다!
            if (a[i][j]=='.'||a[i][j]=='L') waterQ.push({i,j}), visited[i][j]=1;    
            if (a[i][j]=='L') ly = i, lx = j;
        }
    }

    qSwan.push({ly, lx});
    visitedSwan[ly][lx]=1;
    while (1) {
        queue<pair<int,int>> ice, qtempSwan;
        while (qSwan.size()) {
            tie(y,x) = qSwan.front();
            qSwan.pop();

            for (int i=0; i<4; ++i) {
                int ny = dy[i] + y;
                int nx = dx[i] + x;

                if (ny<0||ny>=R||nx<0||nx>=C||visitedSwan[ny][nx]) continue;
                visitedSwan[ny][nx]=1;
                if (a[ny][nx]=='.') qSwan.push({ny,nx});
                else if (a[ny][nx]=='X') qtempSwan.push({ny,nx});
                else if (a[ny][nx]=='L') flag=true;
            }
        }
        if (flag) break;

        while (waterQ.size()) {
            tie(y, x) = waterQ.front();
            waterQ.pop();

            for (int i=0; i<4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny<0||ny>=R||nx<0||nx>=C||visited[ny][nx]) continue;
                visited[ny][nx]=1;
                if (a[ny][nx]=='X') a[ny][nx]='.', ice.push({ny,nx});   // 얼음을 물로 바꿔준다
            }
        }

        waterQ = ice; qSwan=qtempSwan;
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}