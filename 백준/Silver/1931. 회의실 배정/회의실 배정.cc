#include <bits/stdc++.h>
using namespace std;  

int N, cnt, x, y, comp;
vector<pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> x >> y;
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());

    comp=v[0].first; ++cnt;
    for (int i=1; i<N; ++i) {
        if (comp<=v[i].second) ++cnt, comp = v[i].first;
    }
    cout << cnt << '\n';

    return 0;
}
