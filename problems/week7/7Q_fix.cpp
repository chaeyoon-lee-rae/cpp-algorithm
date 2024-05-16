#include <bits/stdc++.h>
using namespace std;  

const int n=18;
bool prime[20];
double p_a, p_b, dp[20][20][20];

double go(int cnt, int a, int b) {
    if (cnt==n) return prime[a] || prime[b] ? 1.0 : 0.0;
    double &ret = dp[cnt][a][b];
    if (ret>-0.5) return ret;
    ret=0.0;
    ret+=go(cnt+1, a+1, b) * p_a * (1-p_b);
    ret+=go(cnt+1, a, b+1) * (1-p_a) * p_b;
    ret+=go(cnt+1, a, b) * (1-p_a) * (1-p_b);
    ret+=go(cnt+1, a+1, b+1) * p_a * p_b;
    return ret;
}

void fillPrime() {
    fill(prime, prime+20, 1);
    for (int i=0; i<=20; ++i) {
        if (i<=1) prime[i]=0;
        if (prime[i]) {
            for (int j=i*i; j<=20; j+=i) prime[j]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p_a >> p_b;
    p_a/=100; p_b/=100;
    fillPrime();
    memset(dp, -1, sizeof(dp));
    cout << setprecision(7);
    cout << go(0,0,0) << '\n';

    return 0;
}
