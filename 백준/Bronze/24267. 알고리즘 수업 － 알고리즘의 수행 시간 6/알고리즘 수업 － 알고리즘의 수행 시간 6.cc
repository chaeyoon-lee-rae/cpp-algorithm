#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
ll N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    N-=2;
    ll sum=0;
    for (ll i=N; i>0; --i) {
        sum += i*(i+1)/2;
    }
    cout << sum << '\n';
    cout << 3 << '\n';

    return 0;
}
