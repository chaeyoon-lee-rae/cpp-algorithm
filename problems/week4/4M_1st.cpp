/*=========================================

▶️ 제목: 피카츄
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

string s;

vector<string> split(string input, string del) {
    vector<string> ret;
    int pos = 0;
    string token="";
    while ((pos=input.find(del))!=string::npos) {
        token=input.substr(0,pos);
        ret.push_back(token);
        input.erase(0, pos+del.length());
    }
    ret.push_back(input);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    vector<string> vs_pi=split(s,"pi");
    for (string val : vs_pi) {
        vector<string> vs_ka=split(val,"ka");
        for (string val2 : vs_ka) {
            vector<string> vs_chu=split(val2,"chu");
            for (string ret : vs_chu) {
                if (ret!="") {cout << "NO" << '\n'; return 0;}
            }
        }
    }
    
    cout << "YES" << '\n';

    return 0;
}