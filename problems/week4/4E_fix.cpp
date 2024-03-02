/*=========================================

▶️ 제목: 경사로
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, L, a[101][101], b[101][101], ret;

void go(int a[101][101]) {
    for (int i=0; i<N; ++i) {
        int cnt=1; int j;
        for (j=1; j<N; ++j) {
            if (a[i][j-1]==a[i][j]) ++cnt;
            else if (a[i][j-1]+1==a[i][j]&&cnt>=L) cnt=1;
            else if (a[i][j-1]-1==a[i][j]&&cnt>=0) cnt=-L+1;
            else break;
        }
        if (j==N && cnt>=0) ++ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> L;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> a[i][j];
            b[j][i]=a[i][j];
        }
    }

    go(a); go(b);
    cout << ret << '\n';

    return 0;
}