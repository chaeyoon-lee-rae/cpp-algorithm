#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int N, pop[11], popSum, ret=INF;
bool visited[11], color[11];
vector<int> v[11];

void dfs(int here, int colored) {
    visited[here]=1;
    for (int there : v[here-1]) {
        if (color[there]==colored && !visited[there]) dfs(there, colored);
    }
}

void go(int node, vector<int> vec1, vector<int> vec2) {
    if (node==N+1) {
        if (!vec1.size()||!vec2.size()) return;
        memset(visited, 0, sizeof(visited)); dfs(vec1[0],1); 
        int numppl=0;
        for (int val:vec1) {
            if (!visited[val]) return;
            numppl += pop[val-1]; 
        }

        memset(visited, 0, sizeof(visited)); dfs(vec2[0],0);
        for (int val:vec2) if (!visited[val]) return;
        ret = min(ret, abs(numppl-(popSum-numppl)));
        return;
    }

    vec1.push_back(node); color[node]=1;
    go(node+1, vec1, vec2);
    vec1.pop_back(); color[node]=0;
    vec2.push_back(node);
    go(node+1, vec1, vec2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> pop[i];
        popSum += pop[i];
    }
    for (int i=0; i<N; ++i) {
        int tempCnt=0; cin >> tempCnt;
        for (int j=0; j<tempCnt; ++j) {
            int temp=0; cin >> temp;
            v[i].push_back(temp);
        }
    }

    vector<int> vec1, vec2;
    go(1, vec1, vec2);
    
    cout << ((ret==INF) ? -1 : ret) << '\n';

    return 0;
}