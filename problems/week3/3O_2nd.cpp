/*=========================================

▶️ 제목: 사다리 조작
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

- 참고) long long으로 INF 구현 → const long long INF = 1e18;
- combi 함수는 꼭 vector로 구현되지 않아도 된다
    - “갯수”를 구하는 문제라면 counter 정수형으로 대체 가능
- 또한 combi 함수는 2차원이라면 이중 for-loop을 사용할 수 있다
    - 처음 combi 함수는 시작하고자하는 값에서 -1 작은 값에서 시작하지만
    - 이 경우라면 시작할 때 시작하고자 하는 값 그대로 매개변수로 넘겨준다
    - 2차 for-loop, j가 1로 시작하여 중복 여부가 있지만 visited로 그 경우는 건너뛴다
- 마지막에 두가지 경우 중 하나를 출력해야할 시 삼항 연산자로 구현하면 간편하다

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF = 1e6;
int N, M, H, tempx, tempy, ret=INF;
bool ladder[34][14];

bool check() {
    for (int i=1; i<=N; ++i) {
        int y=1, x=i;
        while (y<=H) {
            if (ladder[y][x]) ++x;
            else if (ladder[y][x-1]) --x;
            ++y;
        }
        if (x!=i) return false;
    }
    return true;
}

void combi(int start, int cnt){ 
    if (cnt > 3 || cnt >= ret) return;
    if (check()) {ret = min(cnt, ret); return;}
    for(int i = start; i<=H ; ++i){ 
        for (int j=1; j<=N; ++j) {
            if (ladder[i][j] || ladder[i][j-1] || ladder[i][j+1]) continue;
            ladder[i][j] = 1;
            combi(i, cnt+1);
            ladder[i][j] = 0;
        }
    }

    return; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;
    for (int i=0; i<M; ++i) {
        cin >> tempy >> tempx;
        ladder[tempy][tempx]=1;
    }

    combi(1,0);
    cout << ((ret==INF) ? -1 : ret) << '\n';

    return 0;
}