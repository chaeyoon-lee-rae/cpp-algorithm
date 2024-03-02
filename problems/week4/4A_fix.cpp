#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int N, mp, mf, ms, mv, retCost=INF;
struct nut { int p, f, s, v, c; };
vector<nut> nutv;
map<int, vector<vector<int>>> retv;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i=0; i<N; ++i) {
        vector<int> tempv;
        for (int j=0; j<5; ++j) {
            int temp;
            cin >> temp;
            tempv.push_back(temp);
        }
        nutv.push_back({tempv[0],tempv[1],tempv[2],tempv[3],tempv[4]});
    }

    for (int i=0; i<(1<<N); ++i) {
        nut total={0,0,0,0,0};
        vector<int> combv;
        for (int j=0; j<N; ++j) {
            if (i & (1<<j)) {
                total.p += nutv[j].p;
                total.f += nutv[j].f;
                total.s += nutv[j].s;
                total.v += nutv[j].v;
                total.c += nutv[j].c;
                combv.push_back(j+1);
            }
        }
        if ((total.p>=mp)&&(total.f>=mf)&&(total.s>=ms)&&(total.v>=mv)) {
            if (total.c<=retCost) retCost=total.c, retv[retCost].push_back(combv);
        }
    }
    

    if (retCost==INF) cout << -1 << '\n';
    else {
        sort(retv[retCost].begin(), retv[retCost].end());
        cout << retCost << '\n';
        for (int val : retv[retCost][0]) cout << val << " ";
    } 

    return 0;
}