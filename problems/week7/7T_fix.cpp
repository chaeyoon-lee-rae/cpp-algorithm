#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
int n, a[101];
ll dp[101][21]; // 처음에는 cnt로만(dp[101]) 설계했는데... 왜 틀릴까? 왜 sum까지 포함시켜야하지?

ll go(int cnt, int num) {
    if (num<0||num>20) return 0;
    if (cnt==n-2) return num==a[n-1] ? 1 : 0;
    ll &ret=dp[cnt][num];
    if (~ret) return ret; // 선생님 답안에는 0으로 초기화되어 있던데 경우의 수 중에 0이 포함되므로 -1로 초기화 해주어야지 더 효율적이다
    ret=0; 
    ret+=go(cnt+1,num+a[cnt+1]);
    ret+=go(cnt+1,num-a[cnt+1]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    memset(dp,-1,sizeof(dp));
    for (int i=0; i<n; ++i) cin >> a[i];
    cout << go(0,a[0]) << '\n'; // 첫번째 숫자는 음수가 될 수 없으므로 더해줌
    // 만약 처음 숫자가 0이라면? 0을 더해주고 빼주는 경우의 수가 추가되므로 정답x2의 경우의 수를 가져오게 됨

    return 0;
}
