#include <bits/stdc++.h>
using namespace std;  

int ret[27];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (const char& c : s) ++ret[c-'a'];
    for (int i='a'; i<='z'; ++i) cout << ret[i-'a'] << " ";

    return 0;
}
