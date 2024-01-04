#include <bits/stdc++.h>
using namespace std;  

int N, M, a[5][5], vis[5][5], ret;

int count() {
    int sum=0;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            string str="";
            while (vis[i][j]==0 && j<M) {
                str += a[i][j]+'0';
                ++j;
            }
            sum += atoi(str.c_str());
        }
    }
    for (int j=0; j<M; ++j) {
        for (int i=0; i<N; ++i) {
            string str="";
            while (vis[i][j]==1 && i<N) {
                str += a[i][j]+'0';
                ++i;
            }
            sum += atoi(str.c_str());
        }
    }
    return sum;
}

void go(int idx) {
    if (idx==N*M) {
        int sum = count();
        ret = max(ret, sum);
        return;
    }
    vis[idx/M][idx%M]=0;
    go(idx+1);
    vis[idx/M][idx%M]=1;
    go(idx+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        string s; cin >> s;
        for (int j=0; j<M; ++j) {
            a[i][j] = s[j]-'0';
        }
    }

    go(0);
    cout << ret << '\n';

    return 0;
}