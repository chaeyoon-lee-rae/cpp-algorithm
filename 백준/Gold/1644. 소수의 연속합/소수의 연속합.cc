#include <bits/stdc++.h>
using namespace std;  

const int mx=4000001;
int n, sum, ret, k, b[1000001], c[1000001];
bool a[mx];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(a,a+mx,true);
    cin >> n;
    for (int i=2; i*i<=n; ++i) {
        if (a[i]) {
            for (int j=i*i; j<=n; j+=i) {
                a[j]=false;
            }
        }
    }

    for (int i=2; i<=n; ++i) {
        if (a[i]) b[k++]=i;
    }
    for (int i=1; i<=k; ++i) {
        c[i] = c[i-1]+b[i-1];
    }

    int i=0, j=0;
    while(j<=k) {
        if (c[j]-c[i]<n) ++j;
        else if (c[j]-c[i]>n) ++i;
        else ++ret, ++i, ++j;
    }
    cout << ret << '\n';

    return 0;
}
