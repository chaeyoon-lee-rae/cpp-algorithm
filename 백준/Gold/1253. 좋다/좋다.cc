#include <iostream>
#include <algorithm>
using namespace std;

int n, a[2001], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int l = 0, r = n - 1;
        const int& target = a[i];

        while (true) {
            if (l == i) ++l;
            if (r == i) --r;

            if (l >= r) break;

            if (a[l] + a[r] == target) {
                ++cnt;
                break;
            }
            else if (a[l] + a[r] < target)
                ++l;
            else 
                --r;
        }
    }

    cout << cnt << "\n";

    return 0;
}
