#include <bits/stdc++.h>
using namespace std;  

int N, M, J, l, r, temp, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cin >> J;

    l = 1;
    for (int i=0; i<J; i++) {
        r = l + M - 1;
        cin >> temp;
        if (temp >= l && temp <= r) continue;
        else if (temp < l) {
            ret += l - temp;
            l = temp;
        }
        else if (temp > r) {
            ret += temp - r;
            l += temp - r;
        }
    }

    cout << ret << '\n';

    return 0;
}