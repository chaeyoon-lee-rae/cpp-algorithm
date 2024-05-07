#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9, n=10;
bool a[11][11];
int ori[6], ret=INF;

bool checkSquare(int y, int x, int k) {
    if (y+k>n||x+k>n) return false; // 범위 체크 안했고 처음에 >=으로 써서 엣지케이스 발생
    for (int i=y; i<y+k; ++i) 
    for (int j=x; j<x+k; ++j) {
        if (!a[i][j]) return false;
    }
    return true;
}

void fillNum(int y, int x, int k, int num) {
    for (int i=y; i<y+k; ++i)
    for (int j=x; j<x+k; ++j) {
        a[i][j]=num;
    }
}

void go(int i, int j, int cnt) {
    if (cnt>=ret) return; // 가지치기 안해줬었지만 통과함
    if (j==n) { // dfs에서 이렇게 for-loop으로 순회하듯 순회 가능
        go(i+1,0, cnt);
        return;
    }
    if (i==n) {
        ret = min(ret, cnt);
        return;
    }
    if(!a[i][j]) {
        go(i,j+1,cnt);
        return; // 이런 식으로 return을 해주므로 다시 재방문할 일이 없으므로 vis가 굳이 필요없다
    }

    // 재방문 해야하는 곳은 오로지 1이 칠해진 부분
    for (int k=1; k<=5; ++k) {
        if (checkSquare(i,j,k)&&ori[k]<5) {
            fillNum(i,j,k,0); ++ori[k];
            go(i, j+1, cnt+1);
            fillNum(i,j,k,1); --ori[k];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j) {
        cin >> a[i][j];
    }

    go(0,0,0);
    cout << (ret==INF ? -1 : ret) << '\n';

    return 0;
}
