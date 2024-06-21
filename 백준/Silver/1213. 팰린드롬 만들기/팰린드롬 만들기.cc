#include <bits/stdc++.h>
using namespace std;  

string s, start, mid, ret;
int ch[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        ++ch[s[i]-'A'];
    }
    for (int i='A'; i<='Z'; ++i) {
        if (ch[i-'A']) {
            start.append(ch[i-'A']/2,i);
            mid.append(ch[i-'A']%2,i);
        }
    }
    if (mid.size()>1) cout << "I'm Sorry Hansoo" << '\n';
    else {
        ret+=start;
        ret+=mid;
        reverse(start.begin(), start.end());
        ret+=start; cout << ret << '\n';
    }

    return 0;
}
