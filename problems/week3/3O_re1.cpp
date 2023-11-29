/*=========================================

▶️ 제목: 사다리 조작
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 34분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int N, M, H, ret=INF;
bool ladder[34][14];

bool check() {
    for (int i=1; i<=N; ++i) {
        int k=i;
        for (int j=1; j<=H; ++j) {
            if (ladder[j][k]) ++k;
            else if (ladder[j][k-1]) --k;   // if-if 써도 괜찮은지, if-elseif를 써야하는지 구분하기!
        }
        if (k!=i) return false;
    }
    return true;
}

void combi(int start, int cnt) {
    if (cnt>3) return;
    if (check()) {ret=min(ret,cnt); return;}

    for (int i=start; i<=H; ++i) {
        for (int j=1; j<N; ++j) {
            if (ladder[i][j]||ladder[i][j-1]||ladder[i][j+1]) continue;
            ladder[i][j]=1;
            combi(i, cnt+1);
            ladder[i][j]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;
    for (int i=0; i<M; ++i) {
        int y, x;
        cin >> y >> x;
        ladder[y][x]=1;
    }

    combi(1,0);
    cout << ((ret==INF) ? -1 : ret) << '\n';

    return 0;
}