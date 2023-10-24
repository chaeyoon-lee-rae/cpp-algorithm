/*=========================================

▶️ 제목: 효율적인 해킹
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

처음에 시간복잡도를 한번 줄여보고자 한번 visited한 노드는 그 자식 노드의 수를 저장하여
나중에 조회했을 떄 그 자식 노드의 수를 반환하겠끔 하였다만
노드가 양방향으로 되어있을 경우 이 방법이 통하지 않다는 것을 깨달았다.

그리고 시간제한도 넉넉하기 때문에 (5초) 모든 노드마다 자식노드의 수를 반환하는 "무식한" 방법이 통하는 것이다.
시간제한 고려하는 건 아직도 감이 안 온다...

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, M, visited[10004], sum[10004], mx;
vector<int> v[10004], ret;

int go(int here) {
    if (visited[here]) return sum[here];    // 한번 방문한 곳은 다시 방문하지 않고 값을 반환하므로 양방향 간선이 있는 노드에 다시 방문하지 않아 틀림 (❌)
    visited[here] = 1;

    int count = 1;
    for (int there:v[here]) {
        count += go(there);
    }
    sum[here] = count;

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

    for (int i=1; i<=N; ++i) {
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