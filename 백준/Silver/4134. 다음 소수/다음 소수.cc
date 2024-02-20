#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
ll N;

bool isPrime(ll &num) {
    if (num<=1) return false;
    if (num==2||num==3) return true;
    if (num%2==0 || num%3==0) return false;
    for (ll i=5; i*i<=num; ++i) {
        if (num%i==0 || num % (i+2)==0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--) {
        ll temp; cin >> temp;
        while(1) {
            if (isPrime(temp)) {
                cout << temp << '\n';
                break;
            }
            ++temp;
        }
    }

    return 0;
}
