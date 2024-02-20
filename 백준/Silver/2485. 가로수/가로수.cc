#include <bits/stdc++.h>
using namespace std;  

int N, ret, r, a[100001];

int gcd(int a, int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> a[i];
    }
    sort(a,a+N);
    for (int i=1; i<N; ++i) {
        r = gcd(a[i]-a[i-1],r);
    }
    for (int i=1; i<N; ++i) {
        ret += ((a[i] - a[i-1]) / r) - 1;
    }
    cout << ret << '\n';
    

    return 0;
}
