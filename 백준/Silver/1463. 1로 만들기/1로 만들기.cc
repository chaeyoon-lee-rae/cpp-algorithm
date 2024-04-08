#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int n, dp[INF+1];

int go(int n) {
    if (n==1) return 0;
    int &ret=dp[n];
    if (ret) return ret;
    ret=INF;
    if (n%3==0) ret=min(ret,go(n/3)+1);
    if (n%2==0) ret=min(ret,go(n/2)+1);
    ret=min(ret,go(n-1)+1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << go(n) << '\n';

    return 0;
}
