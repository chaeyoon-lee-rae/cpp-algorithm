#include <bits/stdc++.h>
using namespace std;  

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N; --N;
    int cnt=2, i=1, num=0;
    if (N==0) cout << 1 << '\n';
    else {
        while (true) {
            if (N<=num+6*i && N>num) {
                cout << cnt << '\n';
                break;
            }
            num += 6*i; ++i; ++cnt;
        }
    }

    return 0;
}
