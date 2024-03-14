#include <bits/stdc++.h>
using namespace std;  

int n, l, ret, a[101][101], b[101][101];

void solve(int grid[101][101]) {
    for (int i=0; i<n; ++i) {
        int temp=1;
        int j;
        for (j=1; j<n; ++j) {
            if (grid[i][j]-grid[i][j-1]==-1 && temp>=0) temp=-l+1;
            else if (grid[i][j]-grid[i][j-1]==1 && temp>=l) temp=1;
            else if (grid[i][j]==grid[i][j-1]) ++temp;
            else break;
        }
        if (j==n&&temp>=0) ++ret;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> a[i][j];
            b[j][i]=a[i][j];
        }
    }

    solve(a); solve(b);
    cout << ret << '\n';

    return 0;
}
