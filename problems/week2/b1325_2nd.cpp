/*=========================================

▶️ 제목: 효율적인 해킹
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

앞서 말한대로 각 노드마다 모든 자식 노드의 수를 탐색하는 방법이다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, M, visited[10004], mx;
vector<int> v[10004], ret;

int go(int here) {
    visited[here] = 1;      // 탐색하는 노드의 개수를 반환하는 전형적인 함수. 외우자! (⭐️)

    int count = 1;
    for (int there:v[here]) {
        if (!visited[there]) count += go(there);
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }

    mx = -1;
    for (int i=1; i<=N; ++i) {
        memset(visited, 0, sizeof(visited));
        int result = go(i);
        if (result>mx) {
            ret.clear();
            ret.push_back(i);
            mx = result;
        }
        else if (result==mx) ret.push_back(i); 
    }

    sort(ret.begin(), ret.end());
    
    for (int i=0; i<ret.size(); ++i) cout << ret[i] << " ";
    

    return 0;
}