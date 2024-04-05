#include <bits/stdc++.h>
using namespace std;  

int dp[10001], coin[101], n, k, num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    dp[0]=1;
    for (int i=0; i<n; ++i) {
        cin >> num;
        for (int i=num; i<=k; ++i) {
            dp[i]+=dp[i-num];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}
