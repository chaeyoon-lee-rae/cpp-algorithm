#include <bits/stdc++.h>
using namespace std;  

bool dp[2501][2501];
int dp2[2501];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    const int n = s.size();
    // fill dp
    for (int i=0; i<n; ++i) dp[i][i]=1;

    for (int i=0; i<n-1; ++i) {
        if (s[i]==s[i+1]) dp[i][i+1]=1;
    }

    for (int len=2; len<n; ++len) {
        for (int i=0; len+i<n; ++i) {
            if (s[i]==s[i+len]&&dp[i+1][i+len-1])
                dp[i][i+len]=1;
        }
    }

    // fill dp2
    for (int i=0; i<n; ++i) {
        if (dp[0][i]) dp2[i]=1;
        else {
            dp2[i]=i+1;
            for (int j=1; j<=i; ++j)
                if (dp[j][i]) dp2[i]=min(dp2[i],dp2[j-1]+1);
        }
    }

    cout << dp2[n-1] << '\n';

    return 0;
}
