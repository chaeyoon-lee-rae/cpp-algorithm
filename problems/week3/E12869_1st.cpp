/*=========================================

▶️ 제목: 뮤탈리스크
▶️ 풀이 여부: ❌ (시간초과)
▶️ 풀이 시간: 60분
▶️ 풀이 참고: X

bfs가 아닌 dfs로 풀어서 그런지 시간초과가 나왔다. 
완탐문제는 순열, 조합과 더불어 대부분 dfs, bfs로 푸는 것 같기도 하고... 아직 아리까리하다.

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int N, a[5], cnt, ret=INF, dmg[]={9,3,1};
vector<int> v;

void go() {
    bool flag=0;
    vector<int> v2(v.size());
    copy(v.begin(), v.end(), v2.begin());   // 전역변수 v로 순열을 만들고 재귀에 쓰이게 되면 무한루프에 빠지므로 지역변수로 카피해준다.

    for (int i=0; i<N; ++i) {
        if (a[i]>0) flag=1;
    }

    if (flag) {
        queue<pair<int,int>> q;
        do {
            int i=0;
            for (int idx : v2) {
                if (a[idx]>0) {
                    a[idx] -= dmg[i]; q.push({idx,i});
                    ++i;
                } 
            } ++cnt;
            
            go();
            
            while (q.size()) {   // 백트래킹
                auto it = q.front();
                a[it.first] += dmg[it.second]; q.pop();
            } --cnt;
            
        } while(next_permutation(v2.begin(), v2.end()));
    }
    else {
        ret = min(ret, cnt); return;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> a[i];
        v.push_back(i);
    }

    go();

    cout << ret << '\n';

    return 0;
}