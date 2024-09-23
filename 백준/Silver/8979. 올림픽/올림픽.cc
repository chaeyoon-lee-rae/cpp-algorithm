#include <iostream>
#include <map>
using namespace std;

struct medal {
    int g, s, b;
    bool operator < (const medal& temp) const {
        if (g != temp.g) return g > temp.g;
        else if (s != temp.s) return s > temp.s;
        else return b > temp.b;
    }

    bool operator == (const medal& temp) const {
        return g == temp.g && s == temp.s && b == temp.b;
    }

    bool operator != (const medal& temp) const {
        return !(*this == temp);
    }
};

struct medalCmp {
    bool operator() (const medal& l, const medal& r) const {
        return l < r;
    }
};

int n, k, ret;
medal a[1001];
map<medal, int, medalCmp> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    int c, g, s, b;
    for (int i = 0; i < n; ++i) {
        cin >> c >> g >> s >> b;
        ++mp[{g, s, b}];
        a[c] = { g, s, b };
    }

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if ((*it).first != a[k])
            ret += (*it).second;
        else break;
    }

    cout << ++ret << "\n";

    return 0;
}
