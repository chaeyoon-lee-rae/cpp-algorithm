/*=========================================

▶️ 제목: 수학숙제
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 30분
▶️ 풀이 참고: X

out of range 떠서 무슨 일인가 했더니
100글자이면 최대 10^100자리 숫자가 존재할 가능성이 있으므로
long long (10^18)으로도 커버하지 못하는 크기인 것이다.
즉, int형이 아닌 string으로 문제를 풀어야한다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

string s, stemp;
vector<int> v;
int N;

bool isNum(char ch) {
    if (ch - '0' > 9 || ch - '0' < 0) return false;
    else return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;
        for (char ch : s) {
            if (isNum(ch)) stemp.push_back(ch);
            else {
                if (stemp.size()!=0) {
                    v.push_back(stoll(stemp)); 
                }
                stemp = "";
            }
        }
        if (stemp.size()!=0) {
            v.push_back(stoll(stemp)); 
        }
        stemp="";
    }

    sort(v.begin(), v.end());

    for (int a : v) {
        cout << a << '\n';
    }

    return 0;
}
