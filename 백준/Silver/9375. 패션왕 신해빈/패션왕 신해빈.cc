#include <bits/stdc++.h>
using namespace std;  

int K, N, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    while(K--) {
        cin >> N; ret=1;
        unordered_map<string, int> mp;
        for (int i=0; i<N; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            ++mp[s2];
        }
        for (auto it:mp) ret *= it.second+1;
        --ret;
        cout << ret << '\n';
    }

    return 0;
}
