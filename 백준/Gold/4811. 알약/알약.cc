#include <bits/stdc++.h>
using namespace std;  

typedef long long ll;
int t, num;
ll dp[31][31];

ll go(int w, int h) {
    if (w<0||h<0) return 0;
    if (w==0&&h==0) return 1;
    ll &ret=dp[w][h];
    if (ret) return ret;
    return ret=go(w-1,h+1)+go(w,h-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        cin >> num;
        if (!num) break;
        cout << go(num,0) << '\n';
    }

    return 0;
}
