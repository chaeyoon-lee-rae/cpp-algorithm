#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int n, m, lo, hi, a[100001], sum, ret=INF, mx;

bool check(int mid) {
    int temp=0, cnt=0;
    for (int i=0; i<n; ++i) {
        temp+=a[i];
        if (temp>mid) temp=a[i], ++cnt;
    }
    ++cnt;
    // printf("cnt : %d\n", cnt);
    return cnt<=m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; ++i) {
        scanf("%d", a+i);
        sum+=a[i];
        mx = max(mx, a[i]);
    }
    // printf("mx : %d\n", mx);

    lo=1, hi=sum;
    while (lo<=hi) {
        int mid = (lo+hi)/2;
        // printf("mid : %d\n", mid);
        if (mid<mx||!check(mid)) lo=mid+1;
        else {
            ret=min(ret, mid);
            hi=mid-1;
        }
    }
    printf("%d\n", ret);

    return 0;
}
