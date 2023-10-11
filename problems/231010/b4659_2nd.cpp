/*=========================================

▶️ 제목: 비밀번호 발음하기
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 20분
▶️ 풀이 참고: 🙆🏻‍♀️

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

string s;
bool flag, vIncluded;
char ch;
int lval, rval, prev_idx;

bool isVowel(char &ch) {
    if (ch=='a' || ch=='i' || ch=='u' || ch=='e' || ch=='o') return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> s;
        if (s=="end") break;

        flag = false; vIncluded = false; prev_idx = -1;
        // lval, rval 초기화 안해줌 (❌)
        for (int i=0; i<s.size(); i++) {
            ch = s[i];
            if (isVowel(ch)) lval++, rval=0, vIncluded=true;
            else rval++, lval=0;

            if (rval==3 || lval==3) flag = true;

            if (i>=1 && s[prev_idx] == ch && ch!='e' && ch !='o') {
                flag=true;
            }

            prev_idx = i;

            if (flag) break;
        }

        if (flag || !vIncluded) {
            cout << "<" << s << ">" << " is not acceptable." << '\n';
        }
        else cout << "<" << s << ">" << " is acceptable." << '\n';

    }
    

    return 0;
}