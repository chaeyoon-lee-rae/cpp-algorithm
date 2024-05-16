#include <bits/stdc++.h>
using namespace std;  

bool dp[2001][2001];
int n, a[2001], m, s, e;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];

    for (int i=1; i<=n; ++i) dp[i][i]=1;

    for (int i=1; i<=n-1; ++i)
        if (a[i]==a[i+1]) dp[i][i+1]=1;

    for (int len=2; len<n; ++len)
        for (int i=1; i<=n-len; ++i)
            if (a[i]==a[i+len]&&dp[i+1][i+len-1]) dp[i][i+len]=1;

    cin >> m;
    for (int i=0; i<m; ++i) {
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }

    return 0;
}
