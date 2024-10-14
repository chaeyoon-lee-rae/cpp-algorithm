#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);
    int cnt = 0, temp;
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        if (binary_search(a, a+n, temp))
            ++cnt;
    }

    cout << n + m - 2 * cnt << "\n";

    return 0;
}
