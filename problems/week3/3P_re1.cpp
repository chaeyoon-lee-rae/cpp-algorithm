/*=========================================

▶️ 제목: 꽃길
▶️ 풀이 여부: ✅ 
▶️ 풀이 시간: 20분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int N, a[14][14], ret=INF, dy[]={0,-1,0,1}, dx[]={1,0,-1,0};
bool visited[14][14];

bool checkVisited(int y, int x) {
    if (visited[y][x]) return false;
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (visited[ny][nx]) return false;
    }
    return true;
}

void unmarkVisited(int y, int x) {
    visited[y][x]=0;
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        visited[ny][nx]=0;
    }
}

int markVisited(int y, int x) {
    visited[y][x]=1;
    int cost=a[y][x];
    for (int i=0; i<4; ++i) {
        int ny=y+dy[i];
        int nx=x+dx[i];
        visited[ny][nx]=1;
        cost+=a[ny][nx];
    }
    return cost;
}

void combi(int start, int cost, int cnt) {
    if (cnt==3) {ret = min(ret, cost); return;}
    
    for (int i=start; i<N-1; ++i) {
        for (int j=1; j<N-1; ++j) {
            if (checkVisited(i,j)){
                int _cost = markVisited(i,j);
                combi(i, cost+_cost, cnt+1);
                unmarkVisited(i,j);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> a[i][j];
        }
    }

    combi(1, 0, 0);
    cout << ret << '\n';

    return 0;
}