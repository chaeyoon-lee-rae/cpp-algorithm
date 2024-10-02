#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cal, n, budget, temp1, temp2, dp[10001];

int main() {
    while (true) {
        scanf("%d %d.%d", &n, &temp1, &temp2);

        if (n == 0) break;

        memset(dp, 0, sizeof(dp));

        budget = temp1 * 100 + temp2;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d.%d", &cal, &temp1, &temp2);
            int cost = temp1 * 100 + temp2;
            for (int i = cost; i <= budget; ++i)
                dp[i] = max(dp[i], dp[i - cost] + cal);
        }
        printf("%d\n", dp[budget]);
    }

    return 0;
}
