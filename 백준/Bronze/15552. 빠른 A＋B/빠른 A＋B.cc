#include <bits/stdc++.h>
using namespace std;  

int N, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> a >> b;
        cout << a+b << '\n';
    }

    return 0;
}