#include <iostream>
#include <vector>
using namespace std;

int n, num, a[50];
vector<int> v;

void go(int idx, int cnt) {
    if (cnt == 6) {
        for (auto val : v)
            cout << val << " ";
        cout << "\n";
        return;
    }

    for (int i = idx + 1; i < n; ++i) {
        v.push_back(a[i]);
        go(i, cnt + 1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; ++i)
            cin >> a[i];
        go(-1, 0);
        cout << "\n";
    }

    return 0;
}
