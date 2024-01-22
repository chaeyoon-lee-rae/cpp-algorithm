#include <bits/stdc++.h>
using namespace std;  

int x, y, z;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y >> z;
    int sum = x + y + z;
    int mx = max(x, max(y,z));
    if (mx >= sum-mx) sum -= mx - (sum-mx-1);
    cout << sum << '\n';

    return 0;
}
