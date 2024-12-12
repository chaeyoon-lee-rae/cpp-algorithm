#include <iostream>
using namespace std;

const double INF = 1e9;
int a[51], cnt[51], n, ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        double temp = -INF;
        for (int j = i + 1; j < n; ++j) {
            double d = double(a[j] - a[i]) / (j - i);
            if (d > temp) {
                ++cnt[i]; ++cnt[j];
                temp = d;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        ret = max(ret, cnt[i]);
    cout << ret << "\n";

    return 0;
}
