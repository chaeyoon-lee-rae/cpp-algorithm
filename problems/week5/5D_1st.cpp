#include <bits/stdc++.h>
using namespace std;  

int N, ret;
vector<pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int a, t; cin >> a >> t;
        v.push_back({a,t});
    }
    sort(v.begin(), v.end());
    for (int i=0; i<N; ++i) {
        ret = max(ret, v[i].first);
        ret += v[i].second;
    }
    cout << ret << '\n';

    return 0;
}
