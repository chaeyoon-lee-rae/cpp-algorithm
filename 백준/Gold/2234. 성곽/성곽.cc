#include <bits/stdc++.h>
using namespace std;  

int N, M, mp[51][51], ret1, ret2, ret3, visited[51][51], cntSum[51];
pair<int,int> d[] = {{0,-1},{-1,0},{0,1},{1,0}};

int dfs(int y, int x, int id) {
    if (visited[y][x]) return 0;
    visited[y][x]=id;
    int cnt=1;
    for(int i=0; i<4; ++i) {
        if (!(mp[y][x] & (1<<i))) {
            int ny=y+d[i].first;
            int nx=x+d[i].second;
            cnt += dfs(ny,nx,id);
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> mp[i][j];
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (!visited[i][j]) {
                ++ret1;
                cntSum[ret1] = dfs(i, j, ret1);
                ret2 = max(ret2, cntSum[ret1]);
            }
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (i+1<N) {
                int id1=visited[i][j];
                int id2=visited[i+1][j];
                if (id1!=id2) ret3 = max(ret3, cntSum[id1]+cntSum[id2]);
            }
            if (j+1<M) {
                int id1=visited[i][j];
                int id2=visited[i][j+1];
                if (id1!=id2) ret3 = max(ret3, cntSum[id1]+cntSum[id2]);
            }
        }
    }

    cout << ret1 << '\n';
    cout << ret2 << '\n';
    cout << ret3 << '\n';
    

    return 0;
}