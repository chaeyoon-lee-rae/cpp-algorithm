/*=========================================

▶️ 제목: 괄호
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: 🙅🏻‍♀️

stack을 써야하는 줄 몰라 counter를 계산하여 counter가 0일 때와 아닐 때를 구분하였더니 성공.
하지만 폭발, 짝짓기, 괄호같은 문제는 stack을 쓰도록 하자.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, val;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;
        val = 0;
        for (char ch : s) {
            if (ch=='(') val++;
            if (ch==')') val--;
            if (val < 0) break;
        }
        if (val==0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}