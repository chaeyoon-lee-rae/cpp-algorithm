#include <bits/stdc++.h>
using namespace std;  

int dp[20][20][3], n;
bool a[20][20];


bool check(int y, int x, int d) {
    if (d==0||d==2) {
        if (!a[y][x]) return true;
    } else {
        if (!a[y][x]&&!a[y-1][x]&&!a[y][x-1]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> a[i][j];
        }
    }

    // 0=가로 1=대각선 2=세로
    dp[0][1][0]=1;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (check(i,j+1,0)) dp[i][j+1][0] += dp[i][j][0];
            if (check(i+1,j+1,1)) dp[i+1][j+1][1] += dp[i][j][0];

            if (check(i+1,j,2)) dp[i+1][j][2] += dp[i][j][2];
            if (check(i+1,j+1,1)) dp[i+1][j+1][1] += dp[i][j][2];

            if (check(i,j+1,0)) dp[i][j+1][0] += dp[i][j][1];
            if (check(i+1,j,2)) dp[i+1][j][2] += dp[i][j][1];
            if (check(i+1,j+1,1)) dp[i+1][j+1][1] += dp[i][j][1];
        }
    }

    const int e=n-1;
    cout << dp[e][e][0]+dp[e][e][1]+dp[e][e][2] << '\n';

    return 0;
}
