#include <bits/stdc++.h>
using namespace std;  

int dp[10001], n, cal, d1, d2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        scanf("%d %d.%d", &n, &d1, &d2);
        if (n==0) break;
        int limit=d1*100+d2;
        memset(dp, 0, sizeof(dp));
        for (int i=0; i<n; ++i) {
            scanf("%d %d.%d", &cal, &d1, &d2);
            int cost=d1*100+d2;
            for (int j=cost; j<=limit; ++j) {
                dp[j]=max(dp[j], dp[j-cost]+cal);
            }
        }
        printf("%d\n", dp[limit]);
    }

    return 0;
}
