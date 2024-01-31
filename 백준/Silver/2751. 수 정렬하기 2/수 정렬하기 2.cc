#include <bits/stdc++.h>
using namespace std;  

const int len = 1e6+1;
int a[len], N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> a[i];
    }
    sort(a, a+N);
    for (int i=0; i<N; ++i) cout << a[i] << '\n';

    return 0;
}