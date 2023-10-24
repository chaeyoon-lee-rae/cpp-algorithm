/*=========================================

▶️ 제목: 트리
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

루트노드를 따로 저장하여 dfs함수로 넘겨주었더니 성공

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, temp, a, root, cnt, visited[50];
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
        if (temp==-1) {root=i; continue;}
        v[temp].push_back(i);
    }
    cin >> a;

    if (a==root) cnt=0;     // 루트노드와 비교한다
    else go(root);

    cout << cnt << '\n';

    return 0;
}