#include <bits/stdc++.h>
using namespace std;  

int N, M, a[5][5], ret;
bool b[5][5];

int calc(int &num) {
    int sum=0;
    for (int i=0; i<N; ++i) {
        int temp=0;
        for (int j=0; j<M; ++j) {
            if (num&(1<<(M*i+j))) temp=temp*10+a[i][j];
            else sum+=temp, temp=0;
        }
        sum+=temp;
    }
    for (int j=0; j<M; ++j) {
        int temp=0;
        for (int i=0; i<N; ++i) {
            if ((num&(1<<(M*i+j)))==0) temp=temp*10+a[i][j];
            else sum+=temp, temp=0;
        }
        sum+=temp;
    }
    return sum;
}

void comb(int num, int cnt) {
    if (cnt==N*M) {
        ret = max(ret, calc(num));
        return;
    }

    comb(num, cnt+1);
    comb(num|(1<<cnt), cnt+1);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d", &N, &M);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            scanf("%1d", &a[i][j]);
        }
    }

    comb(0, 0);
    printf("%d\n", ret);

    return 0;
}
