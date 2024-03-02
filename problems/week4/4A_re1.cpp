#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6; int N;
struct Nut {
    int p, f, s, v, c;
} nut[16];
Nut minNut, temp;
vector<vector<int>> retIdx;

bool isAbove (Nut temp) {
    return temp.p >= minNut.p && temp.f >= minNut.f && temp.s >= minNut.s && temp.v >= minNut.v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    minNut.c=INF;
    scanf("%d%d%d%d", &minNut.p, &minNut.f, &minNut.s, &minNut.v);
    for (int i=0; i<N; ++i) {
        auto n = &nut[i];
        scanf("%d%d%d%d%d", &n->p, &n->f, &n->s, &n->v, &n->c);
    }

    for (int i=0; i<(1<<N); ++i) {
        temp.p = temp.f = temp.s = temp.v = temp.c = 0; 
        vector<int> tempIdx;
        for (int j=0; j<N; ++j) {
            if ((1<<j)&i) {
                temp.p += nut[j].p;
                temp.f += nut[j].f;
                temp.s += nut[j].s;
                temp.v += nut[j].v;
                temp.c += nut[j].c;
                tempIdx.push_back(j);
            }
        }
        if (isAbove(temp)) {
            if (temp.c < minNut.c) {
                minNut.c = temp.c;
                retIdx.clear(); 
                retIdx.push_back(tempIdx);
            } else if (temp.c==minNut.c) {
                retIdx.push_back(tempIdx);
            }
        }
    }

    if (minNut.c==INF) printf("-1\n");
    else {
        printf("%d\n", minNut.c);
        sort(retIdx.begin(), retIdx.end());
        for (int i=0; i<retIdx[0].size(); ++i) {
            printf("%d ", retIdx[0][i]+1);
        }
    }

    return 0;
}
