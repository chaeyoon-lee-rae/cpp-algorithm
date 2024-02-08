#include <bits/stdc++.h>
using namespace std;  

int a[26], N, cnt;
string s, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> s;
        ++a[s[0]-'a'];
        cnt = max(cnt, a[s[0]-'a']);
    }

    for (int i=0; i<26; ++i) {
        if (a[i]>=5) ret += i+'a';
    }

    cout << (ret.empty() ? "PREDAJA" : ret) << '\n';

    return 0;
}
