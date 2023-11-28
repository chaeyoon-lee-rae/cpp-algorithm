/*=========================================

▶️ 제목: 숨바꼭질 5
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 30분
▶️ 풀이 참고: O

답 참고 후 풀이

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int mx=500001;
int N, K, sec=1, visited[2][mx];
queue<int> q;

bool bfs() {
    while(q.size()) {
        K+=sec;
        if (K>=mx) return false;
        if (visited[sec%2][K]) return true;
        
        int qSize = q.size();
        for (int i=0; i<qSize; ++i) {
            int x=q.front();
            q.pop();
            for (int nx:{x-1, x+1, x*2}) {
                if (nx<0||nx>=mx||visited[sec%2][nx]) continue;
                if (nx==K) return true;
                visited[sec%2][nx]=visited[(sec+1)%2][x]+1;
                q.push(nx);
            }
        }
        ++sec;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if (N==K) {cout << 0 << '\n'; return 0;}

    q.push(N);
    visited[0][N]=1;

    if (bfs()) cout << sec << '\n';
    else cout << -1 << '\n';

    return 0;
}