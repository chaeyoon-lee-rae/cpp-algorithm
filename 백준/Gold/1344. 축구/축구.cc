#include <bits/stdc++.h>
using namespace std;  

const int n=18;
bool prime[20];
double dp[20][20][20], a, b;

double go(int idx, int x, int y) {
    if (idx==n) return (prime[x]||prime[y]?1.0f:0.0f);
    double &ret=dp[idx][x][y];
    if (ret>-0.5f) return ret;
    ret=0.0f;
    ret+=go(idx+1,x,y)*(1.0f-a)*(1.0f-b);
    ret+=go(idx+1,x+1,y)*(a)*(1.0f-b);
    ret+=go(idx+1,x,y+1)*(1.0f-a)*(b);
    ret+=go(idx+1,x+1,y+1)*a*b;
    return ret;
}

void fillEra() {
    fill(prime, prime+20, 1);
    for (int i=0; i<20; ++i) {
        if (i<=1) prime[i]=false;
        if (prime[i]) {
            for (int j=i*i; j<20; j+=i) {
                prime[j]=false;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1.0f, sizeof(dp));
    fillEra();

    scanf("%lf %lf", &a, &b);
    a/=100; b/=100;
    printf("%0.6lf", go(0,0,0));

    return 0;
}
