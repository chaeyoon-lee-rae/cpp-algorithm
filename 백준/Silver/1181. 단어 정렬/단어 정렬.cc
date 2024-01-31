#include <bits/stdc++.h>
using namespace std;  

vector<string> v;
int N;

bool cmp(string s1, string s2) {
    if (s1.size()==s2.size()) return s1 < s2;
    return s1.size() < s2.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        string s; cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(),v.end()), v.end());
    for (string val:v) cout << val << '\n';

    return 0;
}