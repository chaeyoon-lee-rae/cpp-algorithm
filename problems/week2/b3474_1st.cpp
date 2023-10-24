/*=========================================

▶️ 제목: 교수가 된 현우
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: O

5의 갯수를 구하는 것까지는 생각해냈는데 5뿐만 아닌 5의 승수도
포함해야하는 것까지는 생각치 못하였다. 아쉽다..
그리고 5는 2의 갯수보다 항상 작으므로 5만 고려하여 계산해도 무방하다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, temp;

int go(int num) {
    int count = 0;
    for (int i=5; num/i>=1; i*=5) {
        count += num / i;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> temp;
        cout << go(temp) << '\n';
    }

    return 0;
}