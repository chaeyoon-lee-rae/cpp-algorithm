#include <bits/stdc++.h>
using namespace std;  

int x, a, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;
    a=64;
    while (x>0) {
        if (x<a) a/=2;
        else if (x>a) ++ret, x-=a;
        else {
            ++ret; break;
        }
    }
    cout << ret << '\n';

    return 0;
}
