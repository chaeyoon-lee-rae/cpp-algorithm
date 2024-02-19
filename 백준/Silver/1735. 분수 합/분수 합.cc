#include <bits/stdc++.h>
using namespace std;  

int a1, b1, a2, b2;

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a1 >> b1 >> a2 >> b2;
    int b = (b1*b2)/gcd(b1,b2);
    a1 *= (b/b1);
    a2 *= (b/b2);
    int a = a1+a2; int g = gcd(a,b);
    if (g) a/=g, b/=g;
    cout << a << ' ' << b << '\n';

    return 0;
}
