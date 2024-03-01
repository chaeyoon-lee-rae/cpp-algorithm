#include <bits/stdc++.h>
using namespace std;  

int N, pSum[100001], temp, ret=-1001, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d", &temp);
        sum+=temp;
        ret = max(ret, sum);
        if(sum<0) sum=0;
    }
    cout << ret << '\n';

    return 0;
}
