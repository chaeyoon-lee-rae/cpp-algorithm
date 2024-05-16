#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
int n, a[101];
ll dp[101][21];

ll go(int cnt, int num) {
    if (num<0||num>20) return 0;
    if (cnt==n-2) return num==a[n-1] ? 1 : 0;
    ll &ret=dp[cnt][num];
    if (~ret) return ret;
    ret=0; 
    ret+=go(cnt+1,num+a[cnt+1]);
    ret+=go(cnt+1,num-a[cnt+1]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    memset(dp,-1,sizeof(dp));
    for (int i=0; i<n; ++i) cin >> a[i];
    cout << go(0,a[0]) << '\n';

    return 0;
}
