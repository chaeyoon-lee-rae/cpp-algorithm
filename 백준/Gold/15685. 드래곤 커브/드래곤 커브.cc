#include <bits/stdc++.h>
using namespace std;  

struct Dragon
{
    int d, g;
    pair<int,int> pos;
} a[21];
int N, x, y, d, g, grid[101][101], dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, ret;
vector<int> vRet;

void go(vector<int> &v, int cnt) {
    if (cnt==0) {
        return;
    }
    int curSize = v.size();
    for (int i=curSize-1; i>=0; --i) {
        v.push_back((v[i]+1)%4);
    }
    go(v, cnt-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d %d %d %d", &x, &y, &d, &g);
        grid[y][x]=1;
        a[i].pos={y,x};
        a[i].d=d; a[i].g=g;
    }
    for (int i=0; i<N; ++i) {
        vector<int> v;
        int y = a[i].pos.first;
        int x = a[i].pos.second;
        int d = a[i].d;
        int g = a[i].g;

        v.push_back(d);
        go(v, g);
        
        for (int dir_:v) {
            int ny = y + dy[dir_];
            int nx = x + dx[dir_];
            grid[ny][nx]=1;
            y=ny, x=nx;
        }
    }
    for (int i=0; i<100; ++i) {
        for (int j=0; j<100; ++j) {
            if (grid[i][j]&&grid[i+1][j]&&grid[i][j+1]&&grid[i+1][j+1]) ++ret;
        }
    }
    printf("%d\n", ret);

    return 0;
}
