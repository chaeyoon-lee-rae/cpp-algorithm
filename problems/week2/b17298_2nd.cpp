/*=========================================

▶️ 제목: 오큰수
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

그래서 최종답을 배열에 차례대로 저장하여 출력하는 방법으로 변경하였다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, temp, a[1000004], ret[1000004];
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    memset(ret, -1, sizeof(ret));

    for (int i=0; i<N; i++) {
        cin >> temp;
        a[i] = temp;
        while (!stk.empty()) {
            if (a[stk.top()] < temp) ret[stk.top()]=temp, stk.pop();
            else break;
        }
        stk.push(i);
    }

    for (int i=0; i<N; i++) cout << ret[i] << " ";

    return 0;
}