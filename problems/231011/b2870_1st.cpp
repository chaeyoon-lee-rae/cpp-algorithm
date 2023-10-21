/*=========================================

▶️ 제목: 수학숙제
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 30분
▶️ 풀이 참고: X

out of range 떠서 무슨 일인가 했더니
100글자이면 최대 10^100자리 숫자가 존재할 가능성이 있으므로
long long (10^18)으로도 커버하지 못하는 크기인 것이다.
즉, int형이 아닌 string으로 문제를 풀어야한다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int H, W, a[104][104];
string s;
char temp;

void go(int y, int x) {
    int nx = x + 1;
    if (nx >= W) return;
    if (a[y][nx]!=0) a[y][nx] = a[y][x] + 1;
    go(y, nx);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(a, -1, sizeof(a));

    cin >> H >> W;
    for (int i=0; i<H; i++) {
        cin >> s;
        for (int j=0; j<W; j++) {
            temp = s[j];
            if (temp=='c') {
                a[i][j]=0;
            }
        }
    }

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (a[i][j]==0) {
                go(i, j);
                break;
            }
        }
    }

    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}