#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9+1, mx=1000001;
int n, lis[mx], num, ret[mx], len;
pair<int,int> b[mx];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(lis,lis+mx,INF);
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &num);
        auto it = lower_bound(lis,lis+len,num);
        int pos = (int)(lower_bound(lis,lis+len,num)-lis);
        if (*it==INF) ++len;
        *it=num;
        b[i].first=pos; b[i].second=num;
    }
    printf("%d\n", len);
    int k=len;
    for (int i=n-1; i>=0; --i) {
        if (b[i].first==k-1) ret[k-1]=b[i].second, --k;
    }
    for (int i=0; i<len; ++i) {
        printf("%d ", ret[i]);
    }

    return 0;
}
