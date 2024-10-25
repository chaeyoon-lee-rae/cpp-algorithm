#include <iostream>
using namespace std;

int n, ret;
pair<int, int> a[16];

void go(int day, int num) {
    if (day == n) {
        ret = max(ret, num);
        return;
    }

    if (day + a[day].first <= n)
        go(day + a[day].first, num + a[day].second);
    go(day + 1, num);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;

    go(0, 0);
    cout << ret << "\n";

    return 0;
}
