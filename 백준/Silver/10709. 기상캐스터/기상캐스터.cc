#include <bits/stdc++.h>
using namespace std;  

int n, m, a[101][101];

void go(int y, int x) {
    while (true) {
        int nx=x+1;
        if (nx>=m||a[y][nx]==0) break;
        a[y][nx]=a[y][x]+1;
        x=nx;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(a,-1,sizeof(a));
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j) {
            char ch; cin >> ch;
            if(ch=='c') a[i][j]=0;
        }
    
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (a[i][j]==0) go(i,j);

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j)
            cout << a[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
