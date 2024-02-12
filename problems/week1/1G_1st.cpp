/*=========================================

▶️ 제목: 한국이 그리울 땐 서버에 접속하지
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 15분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N;
string org, start, last, temp;

bool comp(string &temp) {
    if (start.size()+last.size()<=temp.size()) {
        return temp.substr(0,start.size())==start&&temp.substr(temp.size()-last.size(),last.size())==last;
    } else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> org;
    int i;
    for (i=0; i<org.size(); ++i) {
        if (org[i]!='*') start+=org[i];
        else {++i; break;}
    }
    last = org.substr(i, org.size()-i);

    for (int i=0; i<N; ++i) {
        cin >> temp;
        cout << (comp(temp) ? "DA" : "NE") << '\n';
    }

    return 0;
}
