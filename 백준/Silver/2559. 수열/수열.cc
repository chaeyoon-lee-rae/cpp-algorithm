#include <bits/stdc++.h>
using namespace std;  

const int INF=1e4;
int a[100001], pSum[100001], N, K, ret=-INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i=1; i<=N; ++i) cin>>a[i], pSum[i]=pSum[i-1]+a[i];
    for (int i=K; i<=N; ++i) {
        ret = max(ret, pSum[i]-pSum[i-K]);
    }
    cout << ret << '\n';
    
    return 0;
}
