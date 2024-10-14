#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a, b;
int t, n, m, ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        a.resize(n);
        b.resize(m);

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < m; ++i)
            cin >> b[i];

        ret = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int bval : b) {
            auto it = upper_bound(a.begin(), a.end(), bval);
            ret += a.size() - (it - a.begin());
        }

        cout << ret << "\n";
    }

    return 0;
}
