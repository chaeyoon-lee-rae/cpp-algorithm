#include <bits/stdc++.h>
using namespace std;  

string start, mid, ret;
int a[27];
bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s; cin >> s;
    for (int i=0; i<s.size(); ++i) {
        ++a[s[i]-'A'];
    }

    for (int i=0; i<26; ++i) {
        if (a[i]) {
            start.append(a[i]/2,i+'A');
            mid.append(a[i]%2,i+'A');
        }
    }
    if (mid.size()>1) cout << "I'm Sorry Hansoo" << '\n';
    else {
        ret += start;
        ret += mid;
        reverse(start.begin(), start.end());
        ret += start; cout << ret << '\n';
    }

    return 0;
}
