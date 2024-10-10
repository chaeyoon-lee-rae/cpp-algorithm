#include <iostream>
using namespace std;

typedef long long ll;
int n, m, a[300001], hi, ret;

bool calc(int div) {
    ll cnt = 0;
    for (int i = 0; i < m; ++i) {
        cnt += a[i] / div;
        if (a[i] % div) ++cnt;
    }
    return cnt <= n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        hi = max(hi, a[i]);
    }
        
    int l = 1, r = hi;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (calc(mid)) {
            ret = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ret << "\n";
    

    return 0;
}
