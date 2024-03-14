#include <bits/stdc++.h>
using namespace std;  

int N, x, n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> s;
        if (s=="add") cin >> x, n|=(1<<x);
        else if (s=="remove") cin >> x, n&=~(1<<x);
        else if (s=="check") cin >> x, cout << (n&(1<<x)?1:0) << '\n';
        else if (s=="toggle") cin >> x, n^=(1<<x);
        else if (s=="all") n=(1<<21)-1;
        else n=0;
    }

    return 0;
}
