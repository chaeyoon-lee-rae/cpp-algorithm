#include <bits/stdc++.h>
using namespace std;  

int a[20000], b[20000], n, m, T, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &T);
    while(T--) {
        ret=0;
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; ++i) {
            scanf("%d", a+i);
        }
        for (int i=0; i<m; ++i) {
            scanf("%d", b+i);
        }
        sort(a, a+n);
        sort(b, b+m);

        for (int i=0; i<m; ++i) {
            ret+=a+n-upper_bound(a,a+n,b[i]);
        }
        printf("%d\n",ret);
    }

    return 0;
}
