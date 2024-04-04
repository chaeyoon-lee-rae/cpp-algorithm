#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
int n;
ll dp[31][31];

ll go(int hN, int fN) {
    if (hN<0||fN<0) return 0;
    if (hN==0&&fN==0) return 1;
    ll &ret = dp[hN][fN];
    if (~ret) return ret;
    return ret = go(hN-1, fN) + go(hN+1, fN-1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp,-1,sizeof(dp));
    while(true) {
        cin >> n;
        if (n==0) break;
        cout << go(0,n) << '\n';
    }

    return 0;
}
