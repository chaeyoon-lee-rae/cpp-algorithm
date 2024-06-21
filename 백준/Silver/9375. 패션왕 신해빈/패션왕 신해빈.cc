#include <bits/stdc++.h>
using namespace std;  

int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        map<string,int> mp;
        cin >> n; int ret = 1;
        for (int i=0; i<n; ++i) {
            string s1, s2; cin >> s1 >> s2;
            ++mp[s2];
        }
        for (auto it:mp) ret *= it.second+1;
        cout << --ret << '\n';
    }

    return 0;
}
