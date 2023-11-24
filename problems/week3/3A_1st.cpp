/*=========================================

▶️ 제목: 치킨 배달
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 30분
▶️ 풀이 참고: O

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF = 987654321;      // min값을 도출해내기 위한 임의의 큰 값

int N, M, a[54][54], result=INF;
vector<pair<int,int>> houseList, shopList;
vector<vector<int>> combV;

void combi(int start, vector<int> idxV) {       // 재귀를 이용한 조합함수 (⭐️) 외우자!
    if(idxV.size()==M) {
        combV.push_back(idxV);
        return;
    }
    for(int i=start+1; i<shopList.size(); ++i) {
        idxV.push_back(i);
        combi(i, idxV);
        idxV.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> a[i][j];
            if (a[i][j]==1) houseList.push_back({i,j});
            if (a[i][j]==2) shopList.push_back({i,j});
        }
    }

    vector<int> idxV;
    combi(-1, idxV);

    for (auto it : combV) {
        int ret = 0;
        for (auto house : houseList) {
            int minRet = INF;
            for (int idx : it) {
                int dist = abs(shopList[idx].first - house.first) + abs(shopList[idx].second - house.second);
                minRet = min(minRet, dist);
            }
            ret += minRet;
        }
        result = min(result, ret);
    }

    cout << result << '\n';

    return 0;
}