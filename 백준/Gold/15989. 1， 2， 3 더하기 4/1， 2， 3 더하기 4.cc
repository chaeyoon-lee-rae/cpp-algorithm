#include <bits/stdc++.h>
using namespace std;  

int dp[10001], num, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    dp[0]=1;
    for (int i=1; i<=3; ++i) {
        for (int j=1; j<=10000; ++j) {
            if (j-i>=0) dp[j]+=dp[j-i];
        }
    }
    while(t--) {
        cin >> num;
        cout << dp[num] << '\n';
    }

    return 0;
}
