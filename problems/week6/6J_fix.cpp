#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
const ll INF=6e10+1;
int n, m, a[10001];
ll ret, lo, hi=INF, temp;

bool check(ll mid) {
    temp=m;
    for (int i=0; i<m; ++i) {
        temp+=mid/a[i];
    }
    return temp>=n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        cin >> a[i];
    }
    if (n<=m) cout << n << '\n';
    else {
        lo=1;
        while(lo<=hi) {
            ll mid=(lo+hi)/2;
            if (check(mid)) {
                ret=mid; hi=mid-1;
            } else lo=mid+1;
        }
        
        temp=m;
        for (int i=0; i<m; ++i) {
            temp+=(ret-1)/a[i];
        }
        for (int i=0; i<m; ++i) {
            if (ret%a[i]==0) ++temp;
            if (temp==n) {
                cout << i+1 << '\n';
                break;
            }
        }
    }

    return 0;
}
