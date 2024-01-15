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

    for (auto it:v) {
        if (comp==0||comp<=it.second) ++cnt, comp=it.first;
    }
    cout << cnt << '\n';

    return 0;
}
