#include <bits/stdc++.h>
using namespace std;  

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    int mx = t+t-1;
    int mid = mx/2;
    for (int i=0; i<t; ++i) {
        for (int j=0; j<=mid+i; ++j) {
            cout << ((j>=mid-i) ? '*' : ' ');
        }
        cout << '\n';
    }
    for (int i=t-2; i>=0; --i) {
        for (int j=0; j<=mid+i; ++j) {
            cout << ((j>=mid-i) ? '*' : ' ');
        }
        cout << '\n';
    }

    return 0;
}
