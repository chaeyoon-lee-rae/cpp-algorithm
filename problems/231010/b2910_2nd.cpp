/*
▶️ 제목: 빈도 정렬
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 60분
▶️ 풀이 참고: 🙅🏻‍♀️

그래서 벡터를 사용해봤는데 역시 fail하였다.
정렬하면서 같은 빈도를 가진 요소들이 기존 순서대로 정렬되어 있는 것이 보장되어 있지 않기 때문이다.
그래서 출현한 순서대로 정렬해주는 로직이 필요함.
*/

#include <bits/stdc++.h>
using namespace std;  

int N, C, temp;
vector<pair<int, int>> v;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;         // 빈도만 비교
}

void sortv() {
    sort(v.begin(), v.end(), cmp);      // sort()는 기존 순서를 보존하지 않을 수 있음 (❌)

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

        bool f = false;
        for (auto &it : v) {
            if (it.first == temp) {
                it.second += 1;
                f = true;
                break;
            }
        }
        if (!f) v.push_back({temp, 1});
    }

    sortv();

    return 0;
}