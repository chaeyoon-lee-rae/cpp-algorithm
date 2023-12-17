/*=========================================

▶️ 제목: 게리맨더링
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 60분
▶️ 풀이 참고: O

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int N, pop[11], ret=INF, idx1, idx2;
bool visited[11], color[11];
vector<int> v[11];

pair<int,int> dfs(int here, int colored) {  // dfs로 여러가지 타입의 아웃풋 연습하기
    visited[here]=1;
    pair<int,int> ret = {1,pop[here]};
    for (int there : v[here]) {
        if (color[there]!=colored || visited[there]) continue;
        pair<int,int> temp = dfs(there, colored);
        ret.first += temp.first;
        ret.second += temp.second;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=1; i<=N; ++i) {  // 처음에 1부터 시작하지 않아서 틀림
        cin >> pop[i];
    }
    for (int i=1; i<=N; ++i) {
        int tempCnt=0; cin >> tempCnt;
        for (int j=0; j<tempCnt; ++j) {
            int temp=0; cin >> temp;
            v[i].push_back(temp);
        }
    }

    for (int i=1; i<(1<<N)-1; ++i) {
        memset(color, 0, sizeof(color));
        memset(visited, 0, sizeof(visited));
        idx1=-1, idx2=-1;
        for (int j=0; j<N; ++j) {
            if (i & (1<<j)) color[j+1]=1, idx1=j+1;
            else idx2=j+1;
        }
        pair<int,int> res1 = dfs(idx1, 1);
        pair<int,int> res2 = dfs(idx2, 0);
        if (res1.first + res2.first == N) ret = min(ret, abs(res1.second-res2.second));
    }
    
    cout << ((ret==INF) ? -1 : ret) << '\n';

    return 0;
}