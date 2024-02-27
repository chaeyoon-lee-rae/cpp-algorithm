#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int a[51][51], a_[51][51], N, M, K, ret=INF, dy[]={0,1,0,-1}, dx[]={1,0,-1,0};
struct Rot {int r, c, s;};
vector<Rot> rotv;
vector<int> ordv;


void rotate(vector<pair<int,int>> &posv) {
    int temp = a_[posv[posv.size()-1].first][posv[posv.size()-1].second];
    for (int i=posv.size()-1; i>0; --i) {
        a_[posv[i].first][posv[i].second] = a_[posv[i-1].first][posv[i-1].second];
    }
    a_[posv[0].first][posv[0].second]=temp;
    return;
}

void go(Rot R) {
    for (int s=R.s; s>0; --s) {
        const int miny=R.r-s-1; const int minx=R.c-s-1;
        const int maxy=R.r+s-1; const int maxx=R.c+s-1;
        int y=miny; int x=minx;
        int cnt=0;
        vector<pair<int,int>> posv;
        while (true) {
            posv.push_back({y,x});
            int ny=y+dy[cnt];
            int nx=x+dx[cnt];
            if (ny<miny||ny>maxy||nx<minx||nx>maxx) {
                ++cnt;
                ny=y+dy[cnt];
                nx=x+dx[cnt];
            }
            if (ny==miny&&nx==minx) break;
            y=ny, x=nx;
        }
        rotate(posv);
    }
    return;
}

void calcMin() {
    for (int i=0; i<N; ++i) {
        int sum=0;
        for (int j=0; j<M; ++j) {
            sum+=a_[i][j];
        }
        ret = min(ret,sum);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i=0; i<K; ++i) {
        Rot R;
        scanf("%d %d %d", &R.r, &R.c, &R.s);
        rotv.push_back(R);
        ordv.push_back(i);
    }

    do {
        memcpy(a_, a, sizeof(a));
        for (int i=0; i<ordv.size(); ++i) {
            go(rotv[ordv[i]]);
        }
        calcMin();
    } while (next_permutation(ordv.begin(), ordv.end()));
    cout << ret << '\n';


    return 0;
}
