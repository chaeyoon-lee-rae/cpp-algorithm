/*=========================================

▶️ 제목: 뮤탈리스크
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

"최단 거리"를 구한다는 관점에서 bfs로 풀어야한다고 한다. 
최대 3개 요소로 되어있는 정점에서 공격 데미지들을 순열로 만들어 queue에 삽입된 순서대로 차례대로 빼고빼다보면 
처음 모든 체력이 0으로 되는 레벨이 최단거리, 즉 공격해야하는 횟수의 최솟값인 것이다.
삼차원 배열은 처음이지만 기본원리는 같으므로 익숙해지도록 하자.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, visited[64][64][64], a[3];
vector<vector<int>> dmg;

struct A    // tuple보다 훨씬 낫다.
{
    int a,b,c;
};

queue<A> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> a[i];
    }

    vector<int> d = {9,3,1};
    do {dmg.push_back(d);} while (prev_permutation(d.begin(), d.end()));

    visited[a[0]][a[1]][a[2]]=1;
    q.push({a[0], a[1], a[2]});
    while(q.size()) {
        if (visited[0][0][0]) break;

        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();

        for (int i=0; i<dmg.size(); ++i) {
            int na = max(0, a - dmg[i][0]);
            int nb = max(0, b - dmg[i][1]);
            int nc = max(0, c - dmg[i][2]);
            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c]+1;
            q.push({na, nb, nc});
        }
    }

    cout << visited[0][0][0] - 1 << '\n';

    return 0;
}