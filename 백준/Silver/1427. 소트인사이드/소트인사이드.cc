#include <bits/stdc++.h>
using namespace std;  

string s;
int cnt[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        ++cnt[s[i]-'0'];
    }
    for (int i=9; i>=0; --i) {
        if (cnt[i]) {
            for (int j=0; j<cnt[i]; ++j) cout << i;
        }
    }
    cout << '\n';

    return 0;
}