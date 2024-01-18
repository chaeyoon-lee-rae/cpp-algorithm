#include <bits/stdc++.h>
using namespace std;  

char a[5][16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<5; ++i) {
        string s; cin >> s;
        for (int j=0; j<s.size(); ++j) {
            a[i][j] = s[j];
        }
    }

    for (int j=0; j<15; ++j) {
        for (int i=0; i<5; ++i) {
            if (a[i][j]) cout << a[i][j];
        }
    }

    return 0;
}
