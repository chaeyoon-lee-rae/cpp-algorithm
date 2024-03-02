/*=========================================

▶️ 제목: 피카츄
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: O

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

string s;
bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        if (i<s.size()-1 && (s.substr(i,2)=="pi" || s.substr(i,2)=="ka")) i+=1; // for-loop 넘어가면서 ++i되니 하나 적게 더해준다
        else if (i<s.size()-2 && s.substr(i,3)=="chu") i+=2;
        else flag=1;
    }
    cout << (flag==0 ? "YES" : "NO") << '\n';

    return 0;
}