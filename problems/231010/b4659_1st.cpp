/*
▶️ 제목: 비밀번호 발음하기
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: 🙅🏻‍♀️

누적합 사용해서 구현 (쓸데없이 복잡한 것 같음)
최적화할 수 있는 여지 있음
*/


#include <bits/stdc++.h>
using namespace std;  

string s;
char a[104];
int psum1[104], psum2[104];
bool vc, broke, b[104];


void printr(string &s, bool ret) {
    cout << "<" << s << "> is ";
    if (ret) cout << "acceptable." << '\n';
    else cout << "not acceptable." << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> s;
        if (s=="end") break;

        fill(a, a+104, 0); fill(b, b+104, 0);
        fill(psum1, psum1+104, 0); fill(psum2, psum2+104, 0); 
        vc = false; broke = false;

        for (int i=0; i<s.size(); i++) {
            char ch = s[i];
            a[i+1] = ch;
            
            if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o') {
                vc = true;
                b[i+1] = true;
            }
            else b[i+1] = false;
        }

        for (int i=1; i<s.size()+1; i++) {
            // check 3
            if (a[i] == a[i-1]) {
                psum1[i] = psum1[i-1] + 1;
            }
            else psum1[i] = 1;

            if (a[i] != 'e' && a[i] != 'o' && psum1[i] == 2) {
                printr(s, false);
                broke = true; break;
            }

            // check 2
            if (b[i] == b[i-1]) {
                psum2[i] = psum2[i-1] + 1;
            }
            else psum2[i] = 1;

            if (psum2[i]==3) {
                printr(s, false);
                broke = true; break;
            }
        }

        if (!broke) {
            if (!vc) printr(s, false);
            else printr(s, true);
        }


    }

    return 0;
}