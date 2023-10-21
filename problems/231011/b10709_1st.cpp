/*=========================================

▶️ 제목: 기상캐스터
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: X

방향벡터가 오른쪽만 있다는 것을 기반으로 재귀함수를 구현하였다.
0에서 시작해서 1씩 증가하는 것이므로 같은 열에 0이 여러개 있어도 무방하다.

하지만 2차원 배열을 두번이나 순회하므로 비효율적인 것 같다. (입력받을 때 & 함수호출)

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