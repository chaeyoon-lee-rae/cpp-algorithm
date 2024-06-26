#include <bits/stdc++.h>
using namespace std;  

using ll = long long;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> n) {
        ll num=1; int sz = 1;
        while(true) {
            if (num%n==0) break;
            num=(num*10)+1;
            num%=n;
            ++sz;
        }
        cout << sz << '\n';
    }

    return 0;
}
