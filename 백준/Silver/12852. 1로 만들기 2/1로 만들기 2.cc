#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int dp[1000001], n;

void go(int num) {
    printf("%d ", num);
    if (!(num%3)&&dp[num]==dp[num/3]+1) go(num/3);
    else if (!(num%2)&&dp[num]==dp[num/2]+1) go(num/2);
    else if (num-1>=0&&dp[num]==dp[num-1]+1) go(num-1);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);
    fill(dp, dp+1000001, INF);
    dp[1]=0;
    for (int i=1; i<=n; ++i) {
        int &ret=dp[i];
        if (!(i%3)) ret=min(ret,dp[i/3]+1);
        if (!(i%2)) ret=min(ret,dp[i/2]+1);
        ret=min(ret,dp[i-1]+1);
    }
    printf("%d\n", dp[n]);
    go(n);

    return 0;
}
