#include <bits/stdc++.h>
using namespace std;  

int N, di, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> di;
    int i=1;
    while (di!=0&&i<=N) {
        if (N%i==0) --di, ret=i;
        ++i;
    }
    cout << (di!=0 ? 0 : ret) << '\n';

    return 0;
}
