#include <bits/stdc++.h>
using namespace std;  

int dp[100001], n, k, w, v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d", &n, &k);
    while(n--) {
        scanf("%d %d", &w, &v);
        for (int j=k; j>=w; --j) {
            dp[j]=max(dp[j],dp[j-w]+v);
        }
    }
    printf("%d\n", dp[k]);

    return 0;
}
