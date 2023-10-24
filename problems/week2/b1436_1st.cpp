/*=========================================

▶️ 제목: 영화감독 숌
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

string 기반으로 앞뒤로 숫자들을 붙혀서 vector에 넣어 정렬하였다.
보통 예시로 완탐보다는 시간이 적게 나오는데 완탐으로 풀 수 있으면 완탐으로 푸는 것이...
시간복잡도 계산해서 대략 천만보다 연산량이 적으면은 완탐으로 풀자.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i=0; i<pow(10,4); i++) {
        string s = "000" + to_string(i);
        string a = s.substr(s.size()-4, 4);
        for (int j=0; j<=4; j++) {
            string temp = a.substr(0, 4-j) + "666" + a.substr(4-j,j);
            v.push_back(stoi(temp));
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v[N-1] << '\n';

    return 0;
}