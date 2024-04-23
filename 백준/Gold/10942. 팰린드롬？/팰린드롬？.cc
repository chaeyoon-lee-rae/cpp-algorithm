#include <bits/stdc++.h>
using namespace std;  

int n, a[2001], m, s, e;
bool dp[2001][2001];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", a+i);
    }

    for (int i=0; i<n; ++i) {
        dp[i][i]=1;
    }
    for (int i=0; i<n-1; ++i) {
        if(a[i]==a[i+1]) dp[i][i+1]=1;
    }
    for (int len=2; len<n; ++len) {
        for (int i=0; i<n-len; ++i) {
            if (a[i]==a[i+len]&&dp[i+1][i+len-1]) {
                dp[i][i+len]=1;
            }
        }
    }

    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &s, &e);
        --s, --e;
        printf("%d\n", dp[s][e]);
    }

    return 0;
}
