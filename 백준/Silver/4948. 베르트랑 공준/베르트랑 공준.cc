#include <bits/stdc++.h>
using namespace std;  

int n, ret;

int isPrime(int &num) {
    if (num<=1) return 0;
    for (int i=2; i*i<=num; ++i) {
        if (num%i==0) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        cin >> n; if (n==0) break;
        ret=0;
        for (int i=n+1; i<=2*n; ++i) {
            ret += isPrime(i);
        }
        cout << ret << '\n';
    }

    return 0;
}
