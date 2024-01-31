#include <bits/stdc++.h>
using namespace std;  

int N, ret[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<pair<int,int>> v(N);
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        v[i].first = temp;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    ret[v[0].second]=0;
    int cnt=0;
    for (int i=1; i<N; ++i) {
        if (v[i-1].first!=v[i].first) {
            ++cnt;
        }
        ret[v[i].second]=cnt;
    }

    for (int i=0; i<N; ++i) cout << ret[i] << ' ';

    return 0;
}