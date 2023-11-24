/*=========================================

▶️ 제목: 숨바꼭질 4
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O



=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int len=200004;
int N, K, visited[len], last[len];
queue<int> q;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    q.push(N);
    visited[N]=1;
    while (q.size()) {
        int x = q.front();
        q.pop();

        if (x==K) break;

        for (int nx : {x-1,x+1,x*2}) {
            if (nx<0||nx>=len||visited[nx]) continue;
            q.push(nx);
            visited[nx] = visited[x] + 1;
            last[nx]=x;
        }
    }

    for (int i=K; i!=N; i=last[i]) stk.push(i);
    stk.push(N);

    cout << visited[K] - 1 << '\n';
    while(stk.size()) cout << stk.top() << " ", stk.pop();

    return 0;
}