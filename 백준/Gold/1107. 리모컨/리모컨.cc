#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int mx = 500000;
int n, m, start, ret, r = 2 * mx, l = -mx;
bool buttons[10];

bool check(int num) {
    string s = to_string(num);
    for (char ch : s) {
        if (buttons[ch - '0']) 
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    int t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        buttons[t] = 1;
    }

    ret = abs(100 - n);
    if (m == 10) {
        cout << ret << "\n";
        return 0;
    }

    for (int num = n; num >= 0; --num) {
        if (check(num)) {
            l = num;
            break;
        }
    }
    for (int num = n; num <= 2 * mx; ++num) {
        if (check(num)) {
            r = num;
            break;
        }
    }
    if (abs(r - n) >= abs(l - n))
        t = l;
    else t = r;

    ret = min(ret, int(to_string(t).length()) + abs(t - n));
    cout << ret << "\n";

    return 0;
}
