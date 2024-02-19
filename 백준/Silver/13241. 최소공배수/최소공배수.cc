#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
ll a, b, ret;

ll gcd (ll a, ll b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    ret = (a*b)/gcd(a,b);
    cout << ret << '\n';

    return 0;
}
