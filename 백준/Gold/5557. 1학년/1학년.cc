#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
ll dp[101][21]; int n, a[101];

ll go(int idx, int val) {
    if (val<0||val>20) return 0;
    if (idx==n-2) {
        if (val==a[n-1]) return 1;
        return 0;
    }
    ll &ret=dp[idx][val];
    if (~ret) return ret;
    ret=0;
    ret+=go(idx+1, val+a[idx+1])+go(idx+1, val-a[idx+1]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", a+i);
    }

    memset(dp, -1, sizeof(dp));
    printf("%lld\n", go(0,a[0]));

    return 0;
}
