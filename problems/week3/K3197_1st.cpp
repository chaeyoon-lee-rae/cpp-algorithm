/*=========================================

▶️ 제목: 백조의 호수
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 50분
▶️ 풀이 참고: X

시간 초과가 나버린... 
백조도 물을 따라가다가 얼음을 만나면 멈추는, flood fill 방식을 적용시켰어야한다.(⭐️)
그리고 중간에 변수명 때문에 애를 좀 먹기도 하였다.
조금 길더라도 변수명에 특정한 단어를 포함시켜 분별력을 높이도록 하자!(⭐️)

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int R, C, lx, ly, dy[]={0, -1, 0, 1}, dx[]={1,0,-1,0}, x, y, cnt;
char a[1504][1504];
bool visited[1504][1504], visitedq[1504][1504];
queue<pair<int,int>> q;

bool bfs(int y, int x, queue<pair<int,int>> ql) {
    ql.push({y,x});         // 그리고 처음에 함수 내에 변수를 선언하였는데 함수가 재호출되어도 지역변수는 초기화가 되지 않는다! 주의하도록 (⭐️)
    visitedq[y][x]=1;

    while (ql.size()) {
        tie(y,x) = ql.front();
        ql.pop();

        for (int i=0; i<4; ++i) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny<0||ny>=R||nx<0||nx>=C||visitedq[ny][nx]) continue;
            if (a[ny][nx]=='.') ql.push({ny,nx}), visitedq[ny][nx]=1;
            if (a[ny][nx]=='L') {return true;}
        }
    }
    return false;
}

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
            if (a[i][j]=='.') q.push({i,j});
            if (a[i][j]=='L') ly = i, lx = j;
        }
    }

    while (1) {
        queue<pair<int,int>> ice;
        while (q.size()) {
            tie(y, x) = q.front();
            q.pop();
            visited[y][x]=1;


            for (int i=0; i<4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny<0||ny>=R||nx<0||nx>=C||visited[ny][nx]) continue;
                if (a[ny][nx]=='X') a[ny][nx]='.', ice.push({ny,nx});
            }
        }
        cnt++;
        queue<pair<int,int>> ql;
        memset(visitedq, 0, sizeof(visitedq));
        bool ret = bfs(ly, lx, ql);     // 처음 백조 위치에서 계속 bfs를 돌려서 그런지 시간초과가 나는 것 같다 (❌)
        if (ret) break;
        else q = ice;
    }

    cout << cnt << '\n';

    return 0;
}