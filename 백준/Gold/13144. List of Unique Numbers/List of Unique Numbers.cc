#include <bits/stdc++.h>
using namespace std;  

long long r, l, n, a[100001], cnt;
bool rep[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }

    while(r<n) {
        if (rep[a[r]]) {
            cnt+=r-l;
            rep[a[l]]=0;
            ++l;
        }
        else {
            rep[a[r]]=1;
            ++r;
        }
    }
    cnt+=(r-l)*(r-l+1)/2;
    cout << cnt << '\n';

    return 0;
}
