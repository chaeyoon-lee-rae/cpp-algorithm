#include <iostream>
using namespace std;

int psum[100001], n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    int temp;
    for (int i = 1; i <= n; ++i) {
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }

    int l, r;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        cout << psum[r] - psum[l - 1] << "\n";
    }

    return 0;
}
