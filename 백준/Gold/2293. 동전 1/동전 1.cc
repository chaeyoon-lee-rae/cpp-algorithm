#include <bits/stdc++.h>
using namespace std;  

int dp[10001], n, k, num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0]=1;
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        cin >> num;
        for (int j=num; j<=k; ++j) {
            dp[j]+=dp[j-num];
        }
    }
    cout << dp[k] << '\n';

    return 0;
}
