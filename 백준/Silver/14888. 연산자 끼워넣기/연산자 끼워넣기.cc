#include <bits/stdc++.h>
using namespace std;  

const int INF=1e9;
int a[11], op[4], N, maxNum=-INF, minNum=INF;

int calc(int cnt, int num, int idx) {
    switch (idx)
    {
    case 0:
        num+=a[cnt+1]; break;
    case 1:
        num-=a[cnt+1]; break;
    case 2:
        num*=a[cnt+1]; break;
    case 3:
        num/=a[cnt+1]; break;
    default: break;
    }
    return num;
}

void go(int cnt, int num) {
    if (cnt==N-1) {
        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
        return;
    }
    for (int i=0; i<4; ++i) {
        if (op[i]) {
            --op[i];
            go(cnt+1, calc(cnt, num, i));
            ++op[i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<4; ++i) {
        scanf("%d", &op[i]);
    }
    go(0, a[0]);
    printf("%d\n", maxNum);
    printf("%d\n", minNum);

    return 0;
}
