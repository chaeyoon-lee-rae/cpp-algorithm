#include <bits/stdc++.h>
using namespace std;  

int N, a[1001], mx;
float ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for (int i=0; i<N; ++i) {
        ret += ((float)a[i]/mx * 100);
    }
    cout << ret/N << '\n';

    return 0;
}