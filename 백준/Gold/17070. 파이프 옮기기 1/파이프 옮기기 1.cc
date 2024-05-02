#include <bits/stdc++.h>
using namespace std;  

int n, a[17][17], dp[17][17][3];

bool check(int y, int x, int dir) {
    if (dir==0 || dir==1) {
        if (a[y][x]==0) return true;
    } else {
        if (a[y-1][x]==0&&a[y][x-1]==0&&a[y][x]==0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    dp[0][1][0]=1;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (check(i,j+1,0)) dp[i][j+1][0]+=dp[i][j][0];
            if (check(i+1,j+1,2)) dp[i+1][j+1][2]+=dp[i][j][0];

            if (check(i+1,j,1)) dp[i+1][j][1]+=dp[i][j][1];
            if (check(i+1,j+1,2)) dp[i+1][j+1][2]+=dp[i][j][1];

            if (check(i,j+1,0)) dp[i][j+1][0]+=dp[i][j][2];
            if (check(i+1,j,1)) dp[i+1][j][1]+=dp[i][j][2];
            if (check(i+1,j+1,2)) dp[i+1][j+1][2]+=dp[i][j][2];
        }
    }
    const int c=n-1;
    int ret=dp[c][c][0]+dp[c][c][1]+dp[c][c][2];
    printf("%d\n", ret);

    return 0;
}
