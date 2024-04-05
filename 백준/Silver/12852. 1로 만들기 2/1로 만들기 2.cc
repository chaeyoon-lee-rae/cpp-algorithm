#include <bits/stdc++.h>
using namespace std;  
#define mx 1000001

const int INF=1e9;
int dp[mx], n;

void go(int num) {
    if(num==0) return;
    cout << num << ' ';
    if(num%3==0&&dp[num]==dp[num/3]+1) go(num/3);
    else if (num%2==0&&dp[num]==dp[num/2]+1) go(num/2);
    else if (num-1>=0&&dp[num]==dp[num-1]+1) go(num-1);
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    fill(dp, dp+mx, INF);
    dp[1]=0;
    for (int i=1; i<=n; ++i) {
        if(i%3==0) dp[i]=min(dp[i/3]+1, dp[i]);
        if(i%2==0) dp[i]=min(dp[i/2]+1, dp[i]);
        dp[i]=min(dp[i-1]+1, dp[i]);
    }
    cout << dp[n] << '\n';
    go(n);

    return 0;
}
