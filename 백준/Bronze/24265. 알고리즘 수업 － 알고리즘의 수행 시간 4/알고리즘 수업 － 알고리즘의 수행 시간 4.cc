#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
ll N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    --N;
    cout << N*(N+1)/2 << '\n';
    cout << 2 << '\n';

    return 0;
}
