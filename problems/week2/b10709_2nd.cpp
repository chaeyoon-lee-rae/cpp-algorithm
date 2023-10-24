/*=========================================

▶️ 제목: 기상캐스터
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: X

입력받을 때 몇 분인지 계산하여 2차원 배열에 저장하는 
비교적 효율적인 방법으로 수정하였다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int H, W, a[104][104];
string s;
char temp;

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
                int k = j+1;
                while (k < W) {
                    a[i][k] = a[i][k-1] + 1;
                    k++;
                }
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