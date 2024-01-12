#include <bits/stdc++.h>
using namespace std;  

int a[26];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(a, -1, sizeof(a));
    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        if (a[s[i] - 'a']==-1) a[s[i] - 'a'] = i;
    }
    for (int i=0; i<26; ++i) cout << a[i] << ' ';
    

    return 0;
}
