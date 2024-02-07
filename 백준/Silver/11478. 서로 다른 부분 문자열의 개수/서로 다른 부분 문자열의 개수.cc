#include <bits/stdc++.h>
using namespace std;  

string s;
vector<string> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=1; i<=s.size(); ++i) {
        for (int j=0; j<s.size(); ++j) {
            if (i + j <= s.size()) {
                v.push_back(s.substr(j, i));
            }
        }
    }
    sort(v.begin(),v.end()); 
    cout << unique(v.begin(),v.end())-v.begin() << '\n';

    return 0;
}
