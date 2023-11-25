﻿/*=========================================

▶️ 제목: 보물섬
▶️ 풀이 여부: ✅
▶️ 풀이 시간: 20분
▶️ 풀이 참고: X

=========================================*/

#include <bits/stdc++.h>
using namespace std;  

int N, M, visited[54][54], dy[]={0,-1,0,1}, dx[]={1,0,-1,0}, ret;
char a[54][54];
queue<pair<int,int>> q, land;

int bfs(int y, int x) {
    q.push({y,x});
    visited[y][x]=1;

    int longest=-1;
    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i=0; i<4; ++i) {
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0||ny>=N||nx<0||nx>=M||visited[ny][nx]||a[ny][nx]=='W') continue;
            visited[ny][nx]=visited[y][x]+1;
            longest = max(longest,visited[ny][nx]);     // 여기서 전역변수 사용해서 max를 계속 갱신해줄 수 있음
            q.push({ny,nx});
        }
    }

    return longest;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        string s;
        cin >> s;
        for (int j=0; j<M; ++j) {
            a[i][j] = s[j];
            if (a[i][j]=='L') land.push({i,j});
        }
    }

    while (land.size()) {
        memset(visited, 0, sizeof(visited));
        int y,x;
        tie(y,x) = land.front();
        land.pop();
        ret = max(ret, bfs(y,x));   // 여기서 max를 또 구해줄 필요가 없음
    }

    cout << ret-1 << '\n';

    return 0;
}