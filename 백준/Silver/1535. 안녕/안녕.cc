#include <bits/stdc++.h>
using namespace std;  

int cost[101], dp[101], joy[101], n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; ++i) cin >> cost[i];
    for (int i=0; i<n; ++i) cin >> joy[i];
    for (int i=0; i<n; ++i) {
        for (int j=100; j>cost[i]; --j) {
            dp[j]=max(dp[j],dp[j-cost[i]]+joy[i]);
        }
    }
    cout << dp[100] << '\n';

    return 0;
}
