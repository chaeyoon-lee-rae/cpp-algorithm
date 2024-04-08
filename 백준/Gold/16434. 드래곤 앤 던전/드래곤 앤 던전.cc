#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
const ll INF=1e18;
ll hCur, lo, hi, ret=INF, atk, n, t[123457], atkMon[123457], hMon[123457];

bool check(ll mid) {
    hCur=mid;
    ll curAtk=atk;
    for (int i=0; i<n; ++i) {
        if (t[i]==1) {
            ll pr = (hCur+atkMon[i]-1)/atkMon[i];
            ll pm = (hMon[i]+curAtk-1)/curAtk;
            if (pm<=pr) hCur -= atkMon[i]*(pm-1);
            else return false;
        } else {
            curAtk+=atkMon[i];
            hCur=min(mid,hCur+hMon[i]);
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%lld %lld", &n, &atk);
    for (int i=0; i<n; ++i) {
        scanf("%lld %lld %lld", t+i, atkMon+i, hMon+i);
    }

    lo=1, hi=INF;
    while(lo<=hi) {
        ll mid=(lo+hi)/2;
        if (check(mid)) {
            ret=min(ret,mid);
            hi=mid-1;
        } else lo=mid+1;
    }
    printf("%lld\n", ret);
    return 0;
}
