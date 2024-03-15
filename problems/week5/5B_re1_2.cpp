#include <bits/stdc++.h>
using namespace std;  

string s, rm, ret;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> rm;
    for (int i=0; i<s.size(); ++i) {
        ret+=s[i];
        if (ret.back()==rm[0]) v.push_back(ret.size()-1);
        if (v.size()&&ret.substr(v.back())==rm) {
            ret.erase(v.back());
            v.pop_back();
        }
    }
    cout << (ret.size() ? ret : "FRULA") << '\n';

    return 0;
}
