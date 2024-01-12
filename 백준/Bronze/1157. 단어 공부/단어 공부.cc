#include <bits/stdc++.h>
using namespace std;  

int a[26], mx, c, cnt, ret;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        (s[i]>='a') ? c = s[i]-'a' : c = s[i]-'A';
        ++a[c]; mx = max(mx, a[c]);
    }

    for (int i=0; i<26; ++i) {
        if (a[i]==mx) ++cnt, ret=i;
    }
    if (cnt>1) cout << "?" << '\n';
    else cout << (char)(ret+'A') << '\n';

    return 0;
}
