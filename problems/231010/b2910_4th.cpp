/*=========================================

▶️ 제목: 빈도 정렬
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 30분
▶️ 풀이 참고: 🙆🏻‍♀️

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, C, temp;
vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {                             // 만약 빈도가 같다면
        return mp_first[a.first] < mp_first[b.first];       // 출현 순서대로 정렬해줌
    }
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    for (int i=0; i<N; i++) {
        cin >> temp; mp[temp]++;    // map은 참조하기만 해도 삽입 및 초기화가 되므로 바로 증가시켜줄 수 있음
        if (mp_first[temp] == 0) {      // key 존재 여부 확인 방법 
            mp_first[temp] = i+1;       // 해당 요소의 인덱스 값을 넣어주어 나중에 출현 순서대로 정렬할 수 있게끔 구현 (⭐)
        }
    }

    for (auto &it : mp) {
        v.push_back(it);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto &it : v) {
        for (int i=0; i < it.second; i++) {
            cout << it.first << " ";
        }
    }

    return 0;
}