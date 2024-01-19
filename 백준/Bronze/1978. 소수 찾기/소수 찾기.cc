#include <bits/stdc++.h>
using namespace std;  

int N, num, ret;

int check(int N) {
    if (N<=1) return 0;
    if (N==2) return 1;
    if (N%2==0) return 0;
    for (int i=2; i*i<=N; ++i) {
        if (N%i==0) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> num;
        ret += check(num);
    }
    cout << ret << '\n';

    return 0;
}
