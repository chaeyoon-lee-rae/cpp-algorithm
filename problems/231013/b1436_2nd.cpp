/*=========================================

▶️ 제목: 영화감독 숌
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

주로 사람들이 예시로 많이 드는 완탐방식이다.
N<=10,000이고 연산량은 666*10,000보다 작을테니 완탐으로 가능하다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int i=666;
    for (;;i++) {
       if (to_string(i).find("666")!=string::npos) n--;
       if (n==0) break; 
    }

    cout << i << '\n';

    return 0;
}