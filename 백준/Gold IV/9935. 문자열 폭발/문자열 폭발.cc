#include <bits/stdc++.h>
using namespace std;  

string s, bomb, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> bomb;
    for (int i=0; i<s.size(); ++i) {
        ret += s[i];
        if (ret.size()>=bomb.size() && ret.substr(ret.size()-bomb.size())==bomb) {
            ret.erase(ret.size()-bomb.size());
        }
    }
    cout << (ret!="" ? ret : "FRULA") << '\n';

    return 0;
}
