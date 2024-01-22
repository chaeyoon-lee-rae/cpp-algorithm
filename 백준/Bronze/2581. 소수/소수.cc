#include <bits/stdc++.h>
using namespace std;  

int N, M, num, ret;

int check(int N) {
    if (N<=1) return 0;
    if (N==2) return N;
    if (N%2==0) return 0;
    for (int i=2; i*i<=N; ++i) {
        if (N%i==0) return 0;
    }
    return N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    num = M;
    for (int i=N; i<=M; ++i) {
        if (check(i)) num = min(num, i);
        ret += check(i);
    }
    if (ret) {
        cout << ret << '\n';
        cout << num << '\n';
    }
    else cout << -1 << '\n';

    return 0;
}
