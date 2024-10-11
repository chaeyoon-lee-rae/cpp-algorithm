#include <iostream>
using namespace std;

int n, m, a[100001], hi, l, r, ret, mxlen;

bool check(int len) {
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (sum + a[i] <= len) sum += a[i];
        else ++cnt, sum = a[i];
    }
    if (sum) ++cnt;

    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        hi += a[i];
        mxlen = max(mxlen, a[i]);
    }

    l = mxlen, r = hi;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ret = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ret << "\n";

    return 0;
}
