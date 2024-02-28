#include <bits/stdc++.h>
using namespace std;  

int N, pl, cnt, ret;
vector<pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d", &N, &pl);
    for (int i=0; i<N; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        v.push_back({l,r});
    }
    sort(v.begin(), v.end());
    int s=0;
    for (auto it:v) {
        int l = it.first; int r = it.second;
        if (r<=s) continue;
        if (l<=s) l += s-l+1;
        cnt=(r-l)/pl; if ((r-l)%pl) ++cnt;
        ret+=cnt;
        s=l+(pl*cnt)-1;
    }
    printf("%d\n", ret);

    return 0;
}
