/*=========================================

▶️ 제목: 숨바꼭질 4
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int mx=200001;
int N, K, pre[mx], visited[mx];
queue<int> q;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    if (N==K) {cout << 0 << '\n' << N << '\n'; return 0;}   // 처음에 return 안해줘서 틀림

    q.push(N);
    visited[N]=1;
    while(q.size()) {
        int x=q.front();
        q.pop();
        if (x==K) break;

        for(int nx : {x+1, x-1, x*2}) {
            if (nx<0||nx>=mx||visited[nx]) continue;
            q.push(nx);
            visited[nx]=visited[x]+1;
            pre[nx]=x;
        }
    }

    for (int i=K; i!=N; i=pre[i]) {     // trace 경로 출력하는 법
        v.push_back(i);
    }
    v.push_back(N);
    reverse(v.begin(), v.end());

    cout << visited[K] -1 << '\n';      // 처음에 최단 거리 출력 안해줘서 틀림
    for(int val:v) {cout << val << " ";}

    return 0;
}