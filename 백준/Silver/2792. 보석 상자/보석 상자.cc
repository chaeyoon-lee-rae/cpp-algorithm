#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int n, m, a[300001], hi, lo=1, ret=INF;

bool check(int mid) {
    int num=0;
    for (int i=0; i<m; ++i) {
        num+=a[i]/mid;
        if (a[i]%mid) ++num;
    }
    return n>=num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d", &n, &m);
    for (int i=0; i<m; ++i) {
        scanf("%d", a+i); hi = max(hi, a[i]); 
    }
    while (lo<=hi) {
        int mid = (lo+hi)/2;
        if (check(mid)) {
            ret = min(ret, mid);
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    printf("%d\n", ret);

    return 0;
}
