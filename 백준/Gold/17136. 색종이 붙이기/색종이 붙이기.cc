#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int a[11][11], n, ret=INF, cp[11];

void draw(int y, int x, int len, int val) {
    for (int i=y; i<y+len; ++i) {
        for (int j=x; j<x+len; ++j) {
            a[i][j]=val;
        }
    }
    return;
}

bool check(int y, int x, int len) {
    if (y+len>10||x+len>10) return false;
    for (int i=y; i<y+len; ++i) {
        for (int j=x; j<x+len; ++j) {
            if (a[i][j]==0) return false;
        }
    }
    return true;
}

void dfs(int y, int x, int cnt) {
    if (cnt>=ret) return;
    if (x==10) {
        dfs(y+1, 0, cnt); return;
    }
    if (y==10) {
        ret=min(ret,cnt); return;
    }
    if (a[y][x]==0) {
        dfs(y,x+1,cnt); return;
    }
    for (int i=1; i<=5; ++i) {
        if (cp[i]==5) continue;
        if (check(y,x,i)) {
            ++cp[i];
            draw(y,x,i,0);
            dfs(y,x+i,cnt+1);
            --cp[i];
            draw(y,x,i,1);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            cin >> a[i][j];
        }
    }

    dfs(0,0,0);
    cout << (ret==INF ? -1 : ret) << '\n';

    return 0;
}
