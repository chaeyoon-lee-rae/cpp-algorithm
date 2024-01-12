#include <bits/stdc++.h>
using namespace std;  

int N, sum;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> s;
    for (int i=0; i<N; ++i) {
        sum += s[i] - '0';
    }
    cout << sum << '\n';

    return 0;
}
