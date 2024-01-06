#include <bits/stdc++.h>
using namespace std;  

int K, N, M;
bool visited[1001];
vector<int> adj[1001];

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

    cin >> K;
    while(K--) {
        cin >> N >> M;
        bool flag=0; memset(visited, 0, sizeof(visited));
        for (int i=0; i<1001; ++i) adj[i].clear();
        for (int i=0; i<M; ++i) {
            int node1, node2;
            cin >> node1 >> node2;
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
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