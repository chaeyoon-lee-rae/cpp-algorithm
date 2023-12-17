/*=========================================

▶️ 제목: 동전뒤집기
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int N, a[24], ret=INF;
string s;
vector<int> idxV;

void go(int here) {
    if (here==N+1) {
        int tempRet=0;
        for (int i=0; i<N; ++i) {
            int cnt=0;
            for (int j=0; j<N; ++j) {
                if (a[j] & (1<<i)) ++cnt;
            }
            tempRet += min(cnt, N-cnt);
        }
        ret = min(ret,tempRet);
        return;
    }
    go(here+1);
    a[here]=~a[here];
    go(here+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> s;
        int temp=1;
        for (int j=0; j<N; ++j) {
            if (s[j]=='H') a[i] |= temp;
            temp*=2;
        }
    }

    go(1);
    cout << ret << '\n';

    return 0;
}