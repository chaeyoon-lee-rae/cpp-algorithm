#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int INF = 1e6;
int n, a[21], orig[21], ret = INF;

void check(int k) {
    int cntT = 0;

    for (int i = 0; i < n; ++i) {
        if (k & (1 << i))
            a[i] = ~a[i];
    }

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] & (1 << i)) ++cnt;
        }
        if (cnt <= n/2) cntT += cnt;
        else
            cntT += (n - cnt);
    }

    ret = min(ret, cntT);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int num = 0;
        for (int j = 0; j < n; ++j)
            if (s[j] == 'H') {
                num |= (1 << j);
            }
        a[i] = num;
        orig[i] = num;
    }

    for (int i = 0; i < (1 << n); ++i) {
        check(i);
        memcpy(a, orig, sizeof(orig));
    }

    cout << ret << "\n";

    return 0;
}
