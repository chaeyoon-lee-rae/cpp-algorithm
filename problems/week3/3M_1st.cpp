/*=========================================

▶️ 제목: 부등호
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 50분
▶️ 풀이 참고: X

- 조건문이 너무 길어진다 싶으면 bool 함수로 구현하기
- 완탐할 때 재귀함수에서 매개변수로 넘길 수 있을지 없을지 고민해보기
- 아스키코드 기반으로 숫자를 비교하려면
    - 아스키코드 → 숫자 : n - ‘0’
    - 숫자 → 아스키코드 : n + ‘0’
- cmp 함수 써서 비교하려던 것은 좋았으니 이미 string 길이가 다 같아서 필요가 없었다
    - 정말 필요한 함수인지? 고민해 보아야한다

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int k;
bool visited[15];
char arr[15];
string s;
vector<string> v;

bool cmp(string a, string b) {
    if (a.size()==b.size()) return a<b;
    return a.size() < b.size();
}

void go(int num) {
    if (num==k+1) {v.push_back(s); return;}

    for (int i=0; i<=9; ++i) {
        if (visited[i]) continue;
        if (num!=0) {
            if (!((arr[num-1]=='>' && s[num-1]-'0' > i)||(arr[num-1]=='<' && s[num-1]-'0' < i))) {
                continue;
            }
        }
        visited[i]=1;
        s.push_back(i+'0');
        go(num+1);
        visited[i]=0;
        s.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for (int i=0; i<k; ++i) {
        cin >> arr[i];
    }

    go(0);

    sort(v.begin(), v.end(), cmp);

    cout << v[v.size()-1] << '\n';
    cout << v[0] << '\n';

    return 0;
}