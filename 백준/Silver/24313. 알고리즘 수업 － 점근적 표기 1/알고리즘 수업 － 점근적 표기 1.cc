#include <bits/stdc++.h>
using namespace std;  

int a1, a0, c, n0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a1 >> a0 >> c >> n0;
    cout << (c>=a1 && a1*n0+a0 <= c*n0 ? 1 : 0) << '\n';

    return 0;
}
