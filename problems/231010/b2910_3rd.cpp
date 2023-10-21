/*=========================================

▶️ 제목: 빈도 정렬
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O (chatGPT)

그래서 sort 함수 중에 기존 순서를 보존해주는 stable_sort를 활용하였더니 성공하였다.
하지만 stable_sort가 어떻게 동작하는지 잘 모르는 상태에서 무턱대고 쓰기에는 리스크가 있다.
원하는 기능을 스스로 구현해볼 줄 알아야한다고 생각한다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, C, temp;
vector<pair<int, int>> v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
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

    stable_sort(v.begin(), v.end(), cmp);

    for (auto &it : v) {
        for (int i=0; i < it.second; i++) {
            cout << it.first << " ";
        }
    }

    return 0;
}