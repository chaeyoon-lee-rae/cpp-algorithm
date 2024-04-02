#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
ll dp[91]; int n;

ll fibo(int num) {
    if (num==0|num==1) return num;
    ll &ret=dp[num];
    if(ret) return ret;
    return ret=fibo(num-1)+fibo(num-2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << fibo(n) << '\n';

    return 0;
}
