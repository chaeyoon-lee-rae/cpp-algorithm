#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9+1;
int n, lis[1000001], len, num, ret[1000001];
pair<int,int> b[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(lis, lis+1000001, INF);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> num;
        auto it = lower_bound(lis, lis+len, num);
        int pos = (int)(lower_bound(lis, lis+len, num)-lis);
        if (*it==INF) len++;
        *it=num;
        b[i].first=pos; b[i].second=num;
    }
    cout << len << '\n';
    int k=0;
    for (int i=n-1; i>=0; --i) {
        if (b[i].first==len-1) {
            ret[k]=b[i].second;
            --len; ++k;
        }
    }
    for (int i=k-1; i>=0; --i) {
        cout << ret[i] << ' ';
    }

    return 0;
}
