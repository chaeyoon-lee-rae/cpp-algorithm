#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
const ll INF=1e9+1;
ll s, c, l[1000001], lo, hi, ret, sum;

ll check(ll mid) {
    ll cnt=0;
    for (int i=0; i<s; ++i) {
        cnt+=l[i]/mid;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> c;
    for (int i=0; i<s; ++i) {
        cin >> l[i];
        sum+=l[i];
    }

    lo=1, hi=INF;
    while(lo<=hi) {
        ll mid = (lo+hi)/2;
        ll cnt=check(mid);
        if (cnt>=c) {
            ret = mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout << sum-ret*c << '\n';

    return 0;
}
