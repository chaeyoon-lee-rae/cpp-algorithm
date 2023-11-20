/*=========================================

▶️ 제목: 알파벳
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 30분
▶️ 풀이 참고: X

풀다가 뭔가 잘못되었다 싶어서 다시 보니까 "최대" 몇칸을 지날 수 있냐는 질문을 간과하였다.
BFS로 서칭하다보면 알겠지 했는데 모든 경우의 수를 고려하지 못한다.
즉, 이문제는 모든 경우의 수를 고려하여 최대를 찾는 완전탐색으로 풀어야하는 것이다.

그리고 한번 지나온 알파벳을 확인하는 것이므로 map은 필요없고 visited는 1차원으로도 가능하다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int R, C, dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, y, x, cnt;
char a[54][54];
bool visited[54][54];
string s;
queue<pair<int,int>> q;
map<char,int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for (int i=0; i<R; ++i) {
        cin >> s;
        for (int j=0; j<C; ++j) {
            a[i][j] = s[j];
        }
    }

    q.push({0,0});
    visited[0][0]=1;
    mp[a[0][0]]++;
    while(q.size()) {
        tie(y,x)=q.front();
        q.pop();
        cnt++;

        for (int i=0; i<4; ++i) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if (ny<0||ny>=R||nx<0||nx>=C||visited[ny][nx]) continue;
            if (mp[a[ny][nx]]==0) mp[a[ny][nx]]++, q.push({ny,nx});
        }
    }

    cout << cnt << '\n';

    return 0;
}