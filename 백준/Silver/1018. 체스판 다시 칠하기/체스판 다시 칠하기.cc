#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int N, M, a[51][51], b[51][51], ret=INF;

int calc(int y, int x, int init) {
    memcpy(b, a, sizeof(a));
    int temp = init;
    int cnt=0;
    for (int i=y; i<y+8; ++i) {
        if (b[i][x]!=temp) b[i][x]=temp, ++cnt;
        temp*=-1;
    }
    for (int i=y; i<y+8; ++i) {
        int temp=b[i][x]*-1;
        for (int j=x+1; j<x+8; ++j) {
            if (b[i][j]!=temp) b[i][j]=temp, ++cnt;
            temp*=-1;
        }
    }
    return cnt;
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
            if (s[j]=='W') a[i][j]=-1;
            else a[i][j]=1;
        }
    }

    for (int i=0; i<=N-8; ++i) {
        for (int j=0; j<=M-8; ++j) {
            ret=min(ret,min(calc(i,j,1), calc(i,j,-1)));
        }
    }

    cout << ret << '\n';

    return 0;
}