#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
int n, c, a[31]; ll ret;
vector<ll> v, v2;

void go(ll sum, int idx, int _end, vector<ll> &v) {
    if (sum>c) return;
    if (idx==_end) {v.push_back(sum); return;}
    go(sum+a[idx], idx+1, _end, v);
    go(sum, idx+1, _end, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    for (int i=0; i<n; ++i) cin >> a[i];
    go(0,0,n/2,v);
    go(0,n/2,n,v2);
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for (ll val:v)
        ret += (ll)(upper_bound(v2.begin(),v2.end(),c-val)-v2.begin());

    cout << ret << '\n';
    return 0;
}
