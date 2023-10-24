/*=========================================

▶️ 제목: 빈도 정렬
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

unordered_map 쓰면 삽입 순서대로 key값이 저장되어있을 줄 알았는데 아니었다.
"정렬되지 않는다"는 것은 삽입 순으로 저장되는 것이 보장되지 않는다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

typedef long long int ll;
int N, C, temp;
unordered_map<int, int> mp;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second >= b.second;
}

void sortv(unordered_map<int, int> &M) {
    vector<pair<int, int>> v;

    for (auto &it : M) {
        v.push_back(it);
    }

    sort(v.begin(), v.end(), cmp);

    for (auto &it : v) {
        for (int i=0; i < it.second; i++) {
            cout << it.first << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    for (int i=0; i<N; i++) {
        cin >> temp;
        if(mp.find(temp) == mp.end()) {
            mp[temp] = 1;
        }
        else mp[temp] += 1;
    }

    sortv(mp);

    return 0;
}