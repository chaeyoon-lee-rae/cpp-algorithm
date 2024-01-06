#include <bits/stdc++.h>
using namespace std;  

int K, N, M, adj[1001][1001];
bool visited[1001];

void dfs(int from) {
    visited[from]=1; 
    for (int i=1; i<=N; ++i) {
        if (visited[i]) continue;
        if (adj[from][i]) dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    while(K--) {
        cin >> N >> M;
        bool flag=0; memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<M; ++i) {
            int node1, node2;
            cin >> node1 >> node2;
            if (adj[node1][node2]==0 && adj[node2][node1]==0) {
                ++adj[node1][node2]; ++adj[node2][node1];
            }
        }
        if (flag==0) {
            dfs(1);
            for (int i=1; i<=N; ++i) {
                if (visited[i]==0) {flag=1; break;}
            }
        }
        cout << ((flag==0 && M==N-1)? "tree" : "graph") << '\n';
    }

    return 0;
}