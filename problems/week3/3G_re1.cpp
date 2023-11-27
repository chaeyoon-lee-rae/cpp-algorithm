/*=========================================

▶️ 제목: 숨바꼭질 2
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 30분
▶️ 풀이 참고: O

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int mx=200001;
int N, K, visited[mx], way[mx];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    if (N==K) {cout << 0 << '\n' << 1 << '\n'; return 0;}

    q.push(N);
    visited[N]=1;
    way[N]=1;
    while (q.size()) {
        int x=q.front();
        q.pop();
        if (visited[K]&&visited[x]>visited[K]) break;

        for (int i=0; i<3; ++i) {
            int nx;
            if (i==0) nx=x-1;   // 삼항연산자로 변경가능
            if (i==1) nx=x+1;
            if (i==2) nx=x*2;

            if (nx<0||nx>=mx) continue;
            if (!visited[nx]) {
                visited[nx]=visited[x]+1;
                q.push(nx);
                way[nx]+=way[x];
            } else if (visited[nx]==visited[x]+1) { // 같은 레벨일때만!
                way[nx]+=way[x];
            }
        }
    }

    cout << visited[K]-1 << '\n';
    cout << way[K] << '\n';

    return 0;
}