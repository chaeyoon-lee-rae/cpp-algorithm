#include <bits/stdc++.h>
using namespace std;  

long long ret;
int n, c, a[31];
vector<int> v, v2;

void go(int sum, int idx, int _end, vector<int> &v) {
    if (sum>c) return;
    if (idx==_end) {v.push_back(sum); return;}
    go(sum+a[idx], idx+1, _end, v);
    go(sum, idx+1, _end, v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    for (int i=0; i<n; ++i) cin >> a[i];
    go(0,0,n/2,v);
    go(0,n/2,n,v2);
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for (int val:v)
        ret += (int)(upper_bound(v2.begin(),v2.end(),c-val)-v2.begin());

    cout << ret << '\n';
    return 0;
}
