#include <bits/stdc++.h>
using namespace std;  

int a[101][101], temp[101][101], R, C, M, S[10001], D[10001], Z[10001], dy[]={0,0,1,-1}, dx[]={-1,1,0,0}, ret;
bool caught[10001];

void move(vector<pair<int,int>> &sharkPos) {
    memset(temp, 0, sizeof(temp));
    for (int i=1; i<=M; ++i) {
        if (!caught[i]) {
            int y = sharkPos[i].first, x = sharkPos[i].second;
            int d = D[i], s = S[i], z = Z[i];
            int ny, nx;
            while (true) {
                nx = x + s*dx[d];
                ny = y + s*dy[d];
                if (nx>=0&&nx<C&&ny>=0&&ny<R) break;
                if (d<=1) {
                    if (nx<0) s-=x, x=0;
                    else s-=C-1-x, x=C-1;
                }
                else {
                    if (ny<0) s-=y, y=0;
                    else s-=R-1-y, y=R-1;
                }
                d^=1;
            }
            if (temp[ny][nx]) {
                if (Z[temp[ny][nx]]<z) {
                    caught[temp[ny][nx]]=1;
                    temp[ny][nx]=i;
                } else caught[i]=1;
            } else temp[ny][nx]=i;
            sharkPos[i] = {ny,nx};
            D[i] = d;
        }
    }
    memcpy(a, temp, sizeof(temp));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d %d", &C, &R, &M);
    vector<pair<int,int>> sharkPos(M+1);
    for (int i=1; i<=M; ++i) {
        int c, r, s, d, z;
        scanf("%d %d %d %d %d", &c, &r, &s, &d, &z);
        --r, --c, --d;
        sharkPos[i]={r,c};
        if (d<=1) S[i] = s % (2*(C-1));
        else S[i] = s % (2*(R-1));
        a[r][c]=i; D[i]=d; Z[i]=z;
    }
    for (int i=0; i<R; ++i) {
        for (int j=0; j<C; ++j) {
            if (a[i][j]) {
                ret += Z[a[i][j]];
                caught[a[i][j]]=1;
                a[i][j]=0;
                break;
            }
        }
        move(sharkPos);
    }
    printf("%d\n", ret);

    return 0;
}
