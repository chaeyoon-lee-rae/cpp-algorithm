#include <bits/stdc++.h>
using namespace std;  

int M;
string s;
vector<string> v;

bool cmp(string a, string b) {
    if (a.size()==b.size()) return a<b;
    return a.size() < b.size();
}

string rmZero(string w) {
    while (w[0]=='0' && w.size() > 1) {w=w.substr(1, w.size()-1);}
    return w;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    for (int i=0; i<M; ++i) {
        cin >> s;
        string w;
        for (char ch:s) {
            if (ch < 97) w.push_back(ch);
            else if (ch >= 97 && w.size()) v.push_back(rmZero(w)), w.clear();
        }
        if (w.size()) v.push_back(rmZero(w)), w.clear();
    }

    sort(v.begin(), v.end(), cmp);

    for (int i=0; i<v.size(); ++i) cout << v[i] << '\n';

    return 0;
}