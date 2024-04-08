#include <bits/stdc++.h>
using namespace std;  

int lis[1001], a, n, ret, len;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a;
        auto it=lower_bound(lis,lis+len,a);
        if (*it==0) ++len;
        *it=a;
    }
    cout << len << '\n';

    return 0;
}
