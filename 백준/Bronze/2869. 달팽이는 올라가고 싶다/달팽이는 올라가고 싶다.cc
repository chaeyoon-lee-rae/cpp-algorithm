#include <bits/stdc++.h>
using namespace std;  

int A, B, V;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> V;
    int n = (V - B)/(A - B);
    if ((V - B)%(A - B)) ++n;
    cout << n << '\n';

    return 0;
}
