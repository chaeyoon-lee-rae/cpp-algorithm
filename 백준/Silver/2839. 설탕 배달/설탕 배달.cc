#include <bits/stdc++.h>
using namespace std;  

int N, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N>=3) {
        if (N%5==0) N-=5, ++ret;
        else N-=3, ++ret;
    }
    cout << (N==0 ? ret : -1) << '\n';

    return 0;
}