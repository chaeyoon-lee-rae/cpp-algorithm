#include <bits/stdc++.h>
using namespace std;  

int n, m, k, a[21], cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i=0; i<k; ++i) 
        cin >> a[i];

    int l=1, r=l+m-1;
    for (int i=0; i<k; ++i) {
        int p = a[i];
        if(p<l) cnt+=l-p, r-=l-p, l=p;
        else if(p>r) cnt+=p-r, l+=p-r, r=p;
    }
    cout << cnt << '\n';

    return 0;
}
