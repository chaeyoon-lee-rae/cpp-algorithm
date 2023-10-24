/*=========================================

▶️ 제목: 수학숙제
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: O

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

string s, stemp;
vector<string> v;
int N;

bool isNum(char ch) {
    if (ch - '0' > 9 || ch - '0' < 0) return false;
    else return true;
}

bool cmp(string a, string b) {  // string은 ascii 기반으로 비교하므로 그에 따라 cmp 함수 구현해야함 (⭐️)
    if (a.size()==b.size()) return a < b;   // 자릿수가 같다면 ascii기반으로 비교
    return a.size() < b.size(); // 자릿수가 더 크다면 숫자가 더 큰 것
}

string rmZero(string ori) {     // 이 함수는 재귀아닌 while로도 구현 가능
    if (ori.size()==0) return "0";

    if (ori[0]=='0') {
        ori.erase(0, 1);    // ori.erase(ori.begin())도 가능
        return rmZero(ori);
    }
    else return ori;
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
                    v.push_back(rmZero(stemp));
                }
                stemp = "";     // stemp.clear()도 가능
            }
        }
        if (stemp.size()!=0) {
            v.push_back(rmZero(stemp)); 
        }
        stemp="";
    }

    sort(v.begin(), v.end(), cmp);

    for (auto a : v) {
        cout << a << '\n';
    }

    return 0;
}
