#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int N, ret=INF;
bool a[21][21], temp[21][21];

void countTail() {
    int tempRet=0;
    for (int j=0; j<N; ++j) {
        int cnt=0;
        for (int i=0; i<N; ++i) {
            if (a[i][j]==1) ++cnt;
        }
        if (cnt>N/2) tempRet+=N-cnt;
        else tempRet+=cnt;
    }
    ret=min(ret,tempRet);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            char ch; cin >> ch;
            a[i][j]=ch-'H';
        }
    }
    memcpy(temp, a, sizeof(a));
    
    for (int i=0; i<(1<<N); ++i) {
        for (int j=0; j<N; ++j) {
            if (i&(1<<j)) {
                for (int k=0; k<N; ++k) a[j][k]^=1;
            }
        }
        countTail();
        memcpy(a, temp, sizeof(temp));
    }
    cout << ret << '\n';

    return 0;
}
