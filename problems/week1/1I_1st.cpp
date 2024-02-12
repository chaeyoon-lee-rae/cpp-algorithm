#include <bits/stdc++.h>
using namespace std;  

int N, M;
vector<string> v;
map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        string s; cin >> s;
        mp.insert({s,i+1});
        v.push_back(s);
    }

    for (int i=0; i<M; ++i) {
        string s; cin >> s;
        if (atoi(s.c_str())) {
            int idx = atoi(s.c_str());
            cout << v[--idx] << '\n';
        }
        else {
            cout << mp[s] << '\n';
        }
    }

    return 0;
}
