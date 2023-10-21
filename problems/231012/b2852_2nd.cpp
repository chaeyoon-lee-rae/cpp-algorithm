/*=========================================

▶️ 제목: NBA 농구
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 25분
▶️ 풀이 참고: X

substr()이 있었지... 외우자. 그리고 to_string()으로 숫자에서 문자열로 바꿀 수 있다.
atoi() 는 char *를 입력으로 받고 stoi()는 C++11에 처음 도입된 함수로서 string을 입력으로 받는다. stoi()를 사용하도록 하자.
스타일 방면에서 자릿수에 따라 "0"을 붙히는 로직이 참신하다. 배우자. 그리고 입력받을 때 처리할 수 있는지 최대한 생각해보자.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, t, sec, pt1, pt2, s1, s2, pre;
string s, tempm, temps;

void printRet(int sec) {
    string d = "00"+to_string(sec/60);
    string f = "00"+to_string(sec%60);
    cout << d.substr(d.size()-2, 2) << ":" << f.substr(f.size()-2,2) << '\n';   // 앞에 "0" 붙히는 방법 (⭐️)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> t >> s;
        tempm = s.substr(0,2); temps = s.substr(3,2);   // substr(idx, size) 외우자 (⭐️)
        sec = stoi(tempm) * 60 + stoi(temps);

        if (pt1>pt2) s1 += sec - pre;
        else if (pt2>pt1) s2 += sec - pre;

        t == 1 ? pt1++ : pt2++;     // 삼항연산자 (ternary operator)

        pre = sec;
    }
    if (pt1>pt2) s1 += 48*60 - pre;
    else if (pt2>pt1) s2 += 48*60 - pre;

    printRet(s1);
    printRet(s2);

    return 0;
}