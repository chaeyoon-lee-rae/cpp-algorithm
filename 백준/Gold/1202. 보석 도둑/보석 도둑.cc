#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
ll N, K, m, v, c, ret;
vector<pair<ll,ll>> vj;
vector<ll> vb;
priority_queue<ll> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        cin >> m >> v;
        vj.push_back({m,v});
    }
    for (int i=0; i<K; ++i) {
        cin >> c;
        vb.push_back(c);
    }
    sort(vj.begin(), vj.end());
    sort(vb.begin(), vb.end());

    int j=0;
    for (int i=0; i<K; ++i) {
        while(j<N && vb[i]>=vj[j].first) pq.push(vj[j++].second);
        if(pq.size()) ret+=pq.top(), pq.pop();
    }
    cout << ret << '\n';

    return 0;
}