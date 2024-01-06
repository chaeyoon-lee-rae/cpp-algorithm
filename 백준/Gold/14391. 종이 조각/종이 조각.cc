#include <bits/stdc++.h>
using namespace std;  

int N, M, a[5][5], ret;
string s;

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

    for (int op=0; op<(1<<(N*M)); ++op) {
        int sum=0;
        for (int i=0; i<N; ++i) {
            int num=0;
            for (int j=0; j<M; ++j) {
                int k=i*M+j;
                if ((op&(1<<k))==0) num = num*10 + a[i][j];
                else sum += num, num=0;
            }
            sum += num;     // 포함되지 않은 숫자 꼭 끝에 더해주기
        }
        for (int j=0; j<M; ++j) {
            int num=0;
            for (int i=0; i<N; ++i) {
                int k=i*M+j;
                if ((op&(1<<k))!=0) num = num*10 + a[i][j]; // Boolean 연산때에는 && 아닌 &임 (warning: converting the result of '<<' to a boolean;)
                else sum += num, num=0;
            }
            sum += num;
        }
        ret = max(ret, sum);
    }

    cout << ret << '\n';

    return 0;
}