#include <bits/stdc++.h>
using namespace std;  

int n, m, a[15001], cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a,a+n);
    int l=0, r=n-1;
    while(l<r) {
        if (a[l]+a[r]==m) 
            ++cnt, ++l, --r;
        else if (a[l]+a[r]<m)
            ++l;
        else --r;
    }
    cout << cnt << '\n';

    return 0;
}
