#include <bits/stdc++.h>
using namespace std;  

int lis[101], n, x, y, len;
pair<int,int> a[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> x >> y;
        a[i]={x,y};
    }
    sort(a,a+n);

    for (int i=0; i<n; ++i) {
        auto it=lower_bound(lis,lis+len,a[i].second);
        if (*it==0) ++len;
        *it=a[i].second;
    }
    cout << n-len << '\n';

    return 0;
}
