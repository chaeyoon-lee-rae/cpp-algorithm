#include <bits/stdc++.h>
using namespace std;  

int dp[101][100001], n, t;
pair<int,int> walk[101], bi[101];
const int INF=1e6;

int go(int idx, int time) {
    if (idx==n) return 0;
    int &ret=dp[idx][time];
    if (ret) return ret;
    ret=-INF;
    if (time-walk[idx].first>=0) ret=max(ret, go(idx+1, time-walk[idx].first)+walk[idx].second);
    if (time-bi[idx].first>=0) ret=max(ret, go(idx+1, time-bi[idx].first)+bi[idx].second);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> t;
    for (int i=0; i<n; ++i) {
        cin >> walk[i].first >> walk[i].second;
        cin >> bi[i].first >> bi[i].second;
    }
    cout << go(0,t) << '\n';

    return 0;
}
