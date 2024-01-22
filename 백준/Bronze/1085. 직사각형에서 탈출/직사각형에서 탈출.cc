#include <bits/stdc++.h>
using namespace std;  

int ret, x, y, w, h;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y >> w >> h;
    ret = min(min(x, w-x), min(y, h-y));
    cout << ret << '\n';

    return 0;
}
