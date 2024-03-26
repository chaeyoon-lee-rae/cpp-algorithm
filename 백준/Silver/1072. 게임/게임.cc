#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
const ll INF = 1e10;
ll x, y, z, lo, hi, ret=-1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%lld %lld", &y, &x);
    lo=1, hi=INF;
    while(lo<=hi) {
        ll mid=(lo+hi)/2;
        if ((x+mid)*100 / (y+mid) > x*100/y) {
            ret = mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    printf("%lld\n", ret);

    return 0;
}
