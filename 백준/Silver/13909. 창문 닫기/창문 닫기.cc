#include <bits/stdc++.h>
using namespace std;  

int N, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=1; i*i<=N; ++i) {
        ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}
