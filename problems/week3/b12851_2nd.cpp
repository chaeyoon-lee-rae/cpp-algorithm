/*=========================================

▶️ 제목: 숨바꼭질2
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

BFS를 이용해서 풀려고 한 것은 잘하였으니 경우의 수도 핸들링하는 법 알아두도록 하자!

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int len=100004;
int N, K, visited[len], cnt[len];
queue<int> q;
bool flag;

void bfs() {
    q.push(N);
    visited[N]=1;
    cnt[N]=1;
    while(q.size()) {
        int x = q.front();
        q.pop();
        
        // for (int next : {here+1, here-1, here*2}) -> 이런 방법도 있다
        for (int i=0; i<3; ++i) {
            int nx;
            i==0 ? nx = x - 1 : 
            i==1 ? nx = x + 1 : 
            nx = x * 2;

            if (nx<0||nx>=len) continue;

            if (!visited[nx]) {
                q.push(nx); visited[nx] = visited[x] + 1; cnt[nx] = cnt[x];
            }
            else if (visited[nx] == visited[x]+1) cnt[nx] += cnt[x];    // 카운터를 하나 늘려주는 것이 아닌, 그 전 레벨에 도달하기 까지의 경우의 수를 더해줘야한다! (⭐️)
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if (N==K) {cout << 0 << '\n' << 1 << '\n'; return 0;}   // 엣지케이스 핸들링.. 입력값이 같거나, min값이거나, max값이거나!

    bfs();

    cout << visited[K]-1 << '\n';
    cout << cnt[K] << '\n';

    return 0;
}