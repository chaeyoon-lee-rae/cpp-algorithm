#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int n, dp[10001], k, num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(dp, dp+10001, INF);
    dp[0]=0;

    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        cin >> num;
        for (int j=num; j<=k; ++j) {
            dp[j]=min(dp[j],dp[j-num]+1);
        }
    }
    cout << (dp[k]==INF ? -1 : dp[k]) << '\n';

    return 0;
}
