#include <iostream>
#include <map>
using namespace std;

int n, k, a[1001], ret;
map<int, int, greater<int>> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n >> k;
    int c, g, s, b;
    for (int i = 0; i < n; ++i) {
        cin >> c >> g >> s >> b;
        int sum = g * 100 + s * 10 + b;
        ++mp[sum];
        a[c] = sum;
    }

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if ((*it).first != a[k])
            ret += (*it).second;
        else break;
    }

    cout << ++ret << "\n";

    return 0;
}
