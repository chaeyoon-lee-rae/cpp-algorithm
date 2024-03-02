/*=========================================

▶️ 제목: Tree
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int K, N, M, node1, node2;
vector<int> adj[1001];
bool visited[1001];

void dfs(int from) {
    visited[from]=1; 
    for (int val : adj[from]) {
        if (!visited[val]) dfs(val);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &K);
    while(K--) {
        for (int i=0; i<1001; ++i) adj[i].clear();
        memset(visited, 0, sizeof(visited));
        int cnt=0;
        scanf("%d %d", &N, &M);     // cin 대신 scanf 써봄
        for (int i=0; i<M; ++i) {
            scanf("%d %d", &node1, &node2);
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }
        for (int i=1; i<=N; ++i) {
            if (!visited[i]) dfs(i), ++cnt;     // visited 체크 대신 함수 호출이 몇번 되었는가 체크
        }
        if (cnt==1 && M==N-1) puts("tree");
        else puts("graph");
    }

    return 0;
}