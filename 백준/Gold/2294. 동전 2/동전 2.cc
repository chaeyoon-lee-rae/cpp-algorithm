#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int dp[10001], n, k, num;
vector<int> coin;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(dp, dp+10001, INF);
    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        int temp; cin >> temp;
        coin.push_back(temp);
    }
    sort(coin.begin(), coin.end());
    coin.erase(unique(coin.begin(), coin.end()), coin.end());

    for (int num:coin) {
        for (int i=num; i<=k; ++i) {
            if (!(i%num)) dp[i]=min(dp[i],i/num);
            if (dp[i-num]!=INF) dp[i]=min(dp[i],dp[i-num]+1);
        }
    }
    cout << (dp[k]==INF ? -1 : dp[k]) << '\n';

    return 0;
}
