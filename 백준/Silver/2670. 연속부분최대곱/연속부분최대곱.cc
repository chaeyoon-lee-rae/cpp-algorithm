#include <bits/stdc++.h>
using namespace std;  

int N;
double a, temp, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    temp=1;
    for (int i=0; i<N; ++i) {
        scanf("%lf", &a);
        temp*=a;
        ret=max(ret,temp);
        if (temp<1.0f) {
            temp=1;
        }
    }
    printf("%.3lf\n", ret);

    return 0;
}
