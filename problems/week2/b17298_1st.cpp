/*=========================================

▶️ 제목: 오큰수
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

입력받은 값을 인덱스로 받아 배열에 답을 저장하는 방식으로 하였다만
중복 값은 덮어씌워진다는 것이 문제였다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, temp, b[1000004];
stack<int> stk;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    memset(b, -1, sizeof(b));

    for (int i=0; i<N; i++) {
        cin >> temp;
        v.push_back(temp);
        while (!stk.empty()) {
            int a = stk.top();
            if (a < temp) stk.pop(), b[a]=temp; // 기존에 저장되어있는 답이 덮어씌워짐 (❌)
            else break;
        }
        stk.push(temp);
    }

    for (int c : v) cout << b[c] << " ";

    return 0;
}