#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int n, m, a[100001], mx, lo, hi, ret=INF;

int check(int mid) {
    int bal=0, cnt=0;
    for (int i=0; i<n; ++i) {
        if (bal<a[i]) bal=mid, ++cnt;
        bal-=a[i];
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; ++i) {
        scanf("%d", a+i);
        mx=max(mx,a[i]);
        hi+=a[i];
    }

    lo=1;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if (mid<mx||check(mid)>m) {
            lo=mid+1;
        } else {
            ret=min(ret,mid);
            hi=mid-1;
        } 
    }
    printf("%d\n", ret);

    return 0;
}
