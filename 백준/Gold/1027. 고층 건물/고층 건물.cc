#include <iostream>
using namespace std;

const double INF = 1e9;
int a[51], n, ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        if (i >= 1) {
            double temp = INF;
            for (int j = i - 1; j >= 0; --j) {
                double d = double(a[j] - a[i]) / (j - i);
                if (d < temp) { // d < temp ?
                    ++cnt;
                    temp = d;
                }
            }
        }
        if (i < n - 1) {
            double temp = -INF;
            for (int j = i + 1; j < n; ++j) {
                double d = double(a[j] - a[i]) / (j - i);
                if (d > temp) { // d > temp ?
                    ++cnt;
                    temp = d;
                }
            }
        }
        ret = max(cnt, ret);
    }

    cout << ret << "\n";

    return 0;
}
