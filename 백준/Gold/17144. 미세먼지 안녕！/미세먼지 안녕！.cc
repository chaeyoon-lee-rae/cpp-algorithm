#include <bits/stdc++.h>
using namespace std;  

int R, C, T, a[51][51], cpy[51][51], cnt;
vector<pair<int,int>> v1, v2;

int dy1[] = {0, -1, 0, 1};
int dx1[] = {1, 0, -1, 0};
int dy2[] = {0, 1, 0, -1};
int dx2[] = {1, 0, -1, 0};

vector<pair<int,int>> air(int y_, int x_, int dy[], int dx[]) {
    vector<pair<int,int>> v;
    int cnt = 0;
    int y = y_; int x = x_;
    while(true) {
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];
        if (ny<0||ny==R||nx<0||nx==C) {
            ++cnt;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if (ny==y_ && nx==x_) break;
        y = ny, x = nx;
        v.push_back({y, x});
    }
    return v;
}

void go() {
    memset(cpy, 0, sizeof(cpy));

    queue<pair<int,int>> q;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            if (a[i][j]&&a[i][j]!=-1) q.push({i,j});
        }
    }

    int y, x;
    while (q.size()) {
        tie(y,x) = q.front(); q.pop();
        int p = a[y][x]/5;
        for (int i=0; i<4; ++i) {
            int ny = y + dy1[i];
            int nx = x + dx1[i];
            if (ny<0||ny>=R||nx<0||nx>=C||a[ny][nx]==-1) continue;
            cpy[ny][nx]+=p;
            a[y][x]-=p;
        }
    }

    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            a[i][j]+=cpy[i][j];
        }
    }
    return;
}

void airGO(vector<pair<int,int>> v) {
    for (int i=v.size()-1; i>0; --i) {
        a[v[i].first][v[i].second]=a[v[i-1].first][v[i-1].second];
    }
    a[v[0].first][v[0].second]=0;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C >> T;
    bool flag=0;
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            cin >> a[i][j];
            if (a[i][j]==-1) {
                if (!flag) {
                    v1 = air(i, j, dy1, dx1);
                    flag=1;
                } 
                else v2 = air(i, j, dy2, dx2);
            }
        }
    }

    while(T--) {
        go();
        airGO(v1);
        airGO(v2);
    }

    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            if (a[i][j]!=-1) cnt+=a[i][j];
        }
    }
    cout << cnt << '\n';

    return 0;
}
