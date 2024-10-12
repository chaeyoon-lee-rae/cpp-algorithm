#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[100001], ret, mx;

bool check(int money) {
    //printf("money : %d\n", money);
    int cur = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (cur < a[i]) {
            cur = money;
            ++cnt;
        }
        cur -= a[i];

        //printf("cur : %d, cnt : %d\n", cur, cnt);
    }
    return cnt <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int l = mx, r = int(1e9);
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
