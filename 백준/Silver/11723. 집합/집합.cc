#include <bits/stdc++.h>
using namespace std;  

int N, num, ret;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> s;
        if (s=="add") cin >> num, ret |= (1<<(num-1));
        else if (s=="remove") cin >> num, ret &= ~(1<<(num-1));
        else if (s=="check") cin >> num, cout << ((ret & (1<<(num-1))) ? 1 : 0) << '\n';
        else if (s=="toggle") cin >> num, ret ^= (1<<(num-1));
        else if (s=="all") ret = (1<<20)-1;
        else ret=0;
    }

    return 0;
}