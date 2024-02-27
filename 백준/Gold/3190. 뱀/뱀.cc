#include <bits/stdc++.h>
using namespace std;  

bool apple[101][101], b[101][101]; char turn[10001], temp; 
int ret, N, K, L, y, x, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
queue<pair<int,int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i=0; i<K; ++i) {
        cin >> y >> x;
        apple[--y][--x]=1;
    }
    cin >> L;
    for (int i=0; i<L; ++i) {
        cin >> y >> temp;
        turn[y]=temp;
    }

    int sy=0, sx=0, cnt=0;
    while (ret<=10000) {
        b[sy][sx]=1; q.push({sy,sx});
        // cout << "time : " << ret << '\n';
        // for (int i=0; i<N; ++i) {
        //     for (int j=0; j<N; ++j) {
        //         cout << b[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        if (turn[ret]=='D') ++cnt %= 4; 
        else if (turn[ret]=='L') {
            --cnt;
            if (cnt<0) cnt=3;
        }
        int ny=sy + dy[cnt];
        int nx=sx + dx[cnt];
        if (ny<0||ny>=N||nx<0||nx>=N||b[ny][nx]) break;
        if (apple[ny][nx]) apple[ny][nx]=0;
        else tie(y,x)=q.front(), b[y][x]=0, q.pop();
        ++ret;
        sy=ny; sx=nx;

    }
    cout << ++ret << '\n';

    return 0;
}
