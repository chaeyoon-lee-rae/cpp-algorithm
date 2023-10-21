/*=========================================

▶️ 제목: 균형잡힌 세상
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 55분
▶️ 풀이 참고: O

b9012 괄호 문제처럼 counter 쓰는 방식으로 접근하려다 실패.
스택으로 해야하는구나가 소스라치게 떠올라서 바로 구현하여 성공하였다.
그리고 input에 띄어쓰기가 있으면은 getline 쓰도록 하자.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        string s;
        getline(cin , s);
        if (s==".") break;

        stack<bool> stk;    // stack은 매번 선언하여 초기화 시켜줘야한다
        flag = false;
        for (char ch:s) {
            if (ch=='(') stk.push(true);
            else if (ch=='[') stk.push(false);
            else if (ch==')') {
                if (stk.empty() || stk.top()==false) flag=true;     // if (true||true)일 때 첫번째 조건이 true이면 두번째 조건은 건너뛴다 (⭐️)
                else stk.pop();
            }
            else if (ch==']') {
                if (stk.empty() || stk.top()==true) flag=true;
                else stk.pop();
            }
        }

        if (flag || !stk.empty()) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }

    return 0;
}