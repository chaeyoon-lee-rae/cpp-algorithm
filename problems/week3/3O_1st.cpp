/*=========================================

▶️ 제목: 사다리 조작
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

typedef pair<int,int> pii;

int N, M, H, tempx, tempy, ret;
bool r[34][14], l[34][14];
vector<int> b;

bool check() {
    for (int i=1; i<=N; ++i) {
        int y=1, x=i;
        while (y<=H) {
            if (r[y][x]) ++x;
            else if (l[y][x]) --x;
            ++y;
        }
        if (x!=i) return false;
    }
    return true;
}

void combi(int start, int k){ 
    if(b.size() == k) {
        if (check()) ret=k;
        return;
    }
    for(int i = start + 1; i < (N-1)*H; ++i){ 
        int y = i/(N-1) + 1;
        int x = i%(N-1) + 1;
        if (r[y][x]) continue;
        r[y][x] = 1; l[y][x+1] = 1; b.push_back(i);
        combi(i, k);
        r[y][x] = 0; l[y][x+1] = 0; b.pop_back();
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
        r[tempy][tempx]=1;
        l[tempy][tempx+1]=1;
    }

    ret=-1;
    for (int k=0; k<=3; ++k) {
        b.clear();
        combi(-1, k);
        if (ret!=-1) break;
    }

    cout << ret << '\n';

    return 0;
}