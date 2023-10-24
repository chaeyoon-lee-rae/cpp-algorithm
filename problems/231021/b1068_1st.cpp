/*=========================================

▶️ 제목: 트리
▶️ 풀이 여부: ❌
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

루트 노드가 항상 맨 처음 요소로 주어지지 않는다는 반례가 있었다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, temp, a, cnt, visited[50];
vector<int> v[50];

void go(int here) {
    visited[here] = 1;
    int count = v[here].size();

    for (int there : v[here]) {
        if (there == a) {count--; continue;}
        if (!visited[there]) go(there);
    }

    if (!count) cnt++;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> temp;
        if (temp==-1) continue;
        v[temp].push_back(i);
    }
    cin >> a;

    if (a==0) cnt = 0;      // 맨 첫번째 요소가 루트노드가 아닐 경우가 있음 (❌)
    else go(0);

    cout << cnt << '\n';

    return 0;
}