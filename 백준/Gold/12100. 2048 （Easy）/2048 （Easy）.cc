#include <bits/stdc++.h>
using namespace std;  

int N, ret;
typedef vector<vector<int>> vvi;


void rotate_left_90(vvi &v, int cnt) {
    if (cnt==0) return;
    vvi temp(N, vector<int>(N,0));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            temp[i][j]=v[j][N-i-1];
        }
    }
    v=temp;
    return;
}

void go(vvi v, int cnt) {
    if (cnt==5) {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                ret = max(ret, v[i][j]);
            }
        }
        return;
    }
    for (int i=0; i<4; ++i) {
        rotate_left_90(v,i);
        vvi temp(N, vector<int>(N,0));
        for (int y=0; y<N; ++y) {
            int idx=-1;
            bool flag=0;
            for (int x=0; x<N; ++x) {
                if (v[y][x]) {
                    if (flag && temp[y][idx]==v[y][x]) {
                        temp[y][idx]=v[y][x]*2;
                        flag=0;
                    }
                    else temp[y][++idx]=v[y][x], flag=1;
                }
            }
        }
        go(temp, cnt+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vvi v(N, vector<int>(N,0));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> v[i][j];
        }
    }

    go(v, 0);
    cout << ret << '\n';

    return 0;
}
