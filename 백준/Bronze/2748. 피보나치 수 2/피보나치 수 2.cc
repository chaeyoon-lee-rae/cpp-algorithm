#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
ll dp[91]; int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1]=1;
    for (int i=2; i<=90; ++i) {
        dp[i] = dp[i-1]+dp[i-2];
    }

    cin >> n;
    cout << dp[n] << '\n';


    return 0;
}
