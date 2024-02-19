#include <bits/stdc++.h>
using namespace std;  

int a, b, N, ret;

int gcd(int a, int b) {
    int r = a % b;
    if (r==0) return b;
    return gcd(b, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; 
    while(N--) {
        cin >> a >> b;
        ret = (a*b)/gcd(a, b);
        cout << ret << '\n';
    }

    return 0;
}
