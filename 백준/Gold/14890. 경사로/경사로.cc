#include <bits/stdc++.h>
using namespace std;  

int n, l, ret, a[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i=0; i<n; ++i) {
        int temp=1; bool flag=0;
        for (int j=1; j<n; ++j) {
            if (a[i][j]-a[i][j-1]==-1 && temp>=0) {
                temp=-l+1;
            } else if (a[i][j]-a[i][j-1]==1 && temp>=l) {
                temp=1;
            } else if (a[i][j]==a[i][j-1]) {
                ++temp;
            } else {flag=1; break;}
        }
        if (!flag&&temp>=0) ++ret;
    }
    for (int j=0; j<n; ++j) {
        int temp=1; bool flag=0;
        for (int i=1; i<n; ++i) {
            if (a[i][j]-a[i-1][j]==-1 && temp>=0) {
                temp=-l+1;
            } else if (a[i][j]-a[i-1][j]==1 && temp>=l) {
                temp=1;
            } else if (a[i][j]==a[i-1][j]) {
                ++temp;
            } else {flag=1; break;}
        }
        if (!flag&&temp>=0) ++ret;
    }
    cout << ret << '\n';

    return 0;
}
