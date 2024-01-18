#include <bits/stdc++.h>
using namespace std;  

int N, M, mx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            int num;
            cin >> num;
            if (num > mx) N=i, M=j, mx=num;
        }
    }
    cout << mx << '\n';
    cout << N+1 << ' ' << M+1 << '\n';

    return 0;
}
