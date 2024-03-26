#include <bits/stdc++.h>
using namespace std;  

int n, m, t, a[1000001], b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> a[i];
        }
        sort(a, a+n);
        cin >> m;
        for (int i=0; i<m; ++i) {
            cin >> b;
            cout << (binary_search(a, a+n, b) ? 1 : 0) << '\n'; 
        }
    }

    return 0;
}
