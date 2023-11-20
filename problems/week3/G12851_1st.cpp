/*=========================================

▶️ 제목: 숨바꼭질2
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 
▶️ 풀이 참고: X

왜 메모리 초과...? 와이? 아직까지 모르겠다. (❓)
그리고 같은 레벨 상에서 원하는 숫자가 발견되면 카운터를 하나 늘려주는 방식으로 했는데.. 이는 옳지 않은 방법이다.
그 숫자에 도달하기까지의 경우의 수를 완전히 반영하지 않기 때문이다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
const int len=100004;
int N, K, visited[len], cnt, level;
queue<int> q;
bool flag;

void bfs() {
    q.push(N);
    visited[N]=1;
    while(q.size()) {
        int x = q.front();
        q.pop();
        
        if (visited[x]+1 > visited[K]) return;  // 이건 최단 거리에서 더 깊은 레벨로 갈 경우 리턴해주는 것인데, 사실 시간복잡도 관계상 굳이 처리해줄 필요가 없는 것 같다.

        for (int i=0; i<3; ++i) {
            int nx;
            i==0 ? nx = x - 1 : 
            i==1 ? nx = x + 1 : 
            nx = x * 2;

            if (nx<0||nx>=len) continue;

            q.push(nx);         // q.push도 해당 숫자가 방문하지 않았을 경우에만 넣어준다!
            if (visited[nx]==INF) visited[nx]=visited[x]+1;

            if (nx==K) ++cnt;       // 카운터 하나씩 늘리는 방식은 옳지 않다! 경우의 수 로직을 생각하자 (❌)
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    fill(visited, visited+len, INF);
    bfs();

    cout << visited[K]-1 << '\n';
    if (cnt) cout << cnt << '\n';
    else cout << 1 << '\n';

    return 0;
}