/*=========================================

▶️ 제목: 꽃길
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

const int INF = 1e6;
int N, ret=INF, price[14][14], dy[]={0,-1,0,1}, dx[]={1,0,-1,0};
bool visited[14][14];
vector<int> b;

bool checkrevisit(int y, int x) {
    if (visited[y][x]) return true;
    for (int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (visited[ny][nx]) return true;
    }
    return false;
}

void combi(int start, int sum) {
    if (b.size()==3) {
        ret = min(ret, sum);
        return;
    }
    for (int i=start+1; i<N*N; ++i) {
        int y = i/N;
        int x = i%N;
        if (y==0||x==0||y==N-1||x==N-1||checkrevisit(y,x)) continue;

        int tempSum=0;
        tempSum += price[y][x];
        visited[y][x]=1;
        for (int i=0; i<4; ++i) {
            int ny = y + dy[i]; int nx = x + dx[i];
            tempSum += price[ny][nx]; visited[ny][nx]=1;
        }
        b.push_back(i);
        combi(i, sum+tempSum);
        b.pop_back();
        visited[y][x]=0;
        for (int i=0; i<4; ++i) {
            int ny = y + dy[i]; int nx = x + dx[i]; 
            visited[ny][nx]=0;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> price[i][j];
        }
    }

    combi(-1,0);
    cout << ret << '\n';

    return 0;
}