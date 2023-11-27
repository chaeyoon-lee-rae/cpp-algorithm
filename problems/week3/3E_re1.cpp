/*=========================================

▶️ 제목: 뮤탈리스크
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 27분
▶️ 풀이 참고: X

BFS으로 풀어야하는 줄 까먹고 백트래킹으로 풀었는데 풀리네;

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int N, scv[3], cnt, ret=INF;
vector<vector<int>> vPermu;

bool check() {
    for (int i=0; i<N; ++i) {
        if (scv[i]>0) return true;
    }
    return false;
}

void go(int start, int cnt) {
    if (cnt>ret) return;
    if (!check()) {ret=min(ret, cnt); return;}

    for (int i=start; i<vPermu.size(); ++i) {
        vector<int> back;
        for (int j=0; j<N; ++j) {
            if (scv[j]>0) scv[j] -= vPermu[i][j], back.push_back(j);
        }
        go(i,cnt+1);
        for (int idx : back) {
            scv[idx] += vPermu[i][idx];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> scv[i];
    }

    vector<int> attack={9,3,1};
    do {
        vPermu.push_back(attack);
    } while(prev_permutation(attack.begin(), attack.begin()+N));

    go(0,0);
    cout << ret << '\n';

    return 0;
}