#include <bits/stdc++.h>
using namespace std;  

int N, a[10001], mx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        ++a[temp];
        mx = max(mx, temp);
    }
    for (int i=1; i<=mx; ++i) {
        if (a[i]) {
            for (int j=0; j<a[i]; ++j) {
                cout << i << '\n';
            }
        }
    }

    return 0;
}
