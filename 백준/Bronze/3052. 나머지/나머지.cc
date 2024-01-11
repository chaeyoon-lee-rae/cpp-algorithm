#include <bits/stdc++.h>
using namespace std;  

int temp1, a[42], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<10; ++i) {
        cin >> temp1;
        temp1 %= 42;
        a[temp1] += 1;
    }
    for (int i=0; i<42; ++i) {
        if (a[i]) ++ret;
    }
    cout << ret << '\n';

    return 0;
}