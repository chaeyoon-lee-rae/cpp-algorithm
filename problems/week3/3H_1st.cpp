/*=========================================

▶️ 제목: 숨바꼭질 4
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int len=100004;
int N, K, visited[len];
vector<int> v[len];
queue<int> q;

void bfs() {
    q.push(N);
    visited[N]=1;
    v[N].push_back(N);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int nx : {x-1, x+1, x*2}) {
            if (nx<0||nx>=len) continue;
            if (!visited[nx]) {
                q.push(nx);
                visited[nx] = visited[x]+1;
                v[nx] = v[x]; v[nx].push_back(nx);
            }

            if (nx==K) return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    bfs();

    cout << visited[K] - 1 << '\n';
    for (int it : v[K]) cout << it << " ";

    return 0;
}