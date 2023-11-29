/*=========================================

▶️ 제목: 부등호
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 25분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int k; bool visited[10]; char oper[10];
string s, smin="9999999999", smax; 
vector<string> v;

bool check(int idx, int num) {
    return (oper[idx-1]=='<' && s[idx-1]-'0'<num)||(oper[idx-1]=='>' && s[idx-1]-'0'>num);
}

void go(int idx) {
    if (s.size()==k+1) {
        smin=min(smin, s); smax=max(smax, s);
    }

    for (int num=0; num<=9; ++num) {
        if (check(idx, num)&&!visited[num]) {
            visited[num]=1; s.push_back(num+'0');
            go(idx+1);
            visited[num]=0; s.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for (int i=0; i<k; ++i) {
        cin >> oper[i];
    }

    for (int i=0; i<=9; ++i) {
        visited[i]=1; s.push_back(i+'0');
        go(1);
        visited[i]=0; s.pop_back();
    }
    
    cout << smax << '\n';
    cout << smin << '\n';

    return 0;
}