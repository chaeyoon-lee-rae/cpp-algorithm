#include <bits/stdc++.h>
using namespace std;  

int temp1;
bool a[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<28; ++i) {
        cin >> temp1;
        a[temp1] = 1;
    }
    for (int i=1; i<=30; ++i) {
        if (!a[i]) cout << i << '\n';
    }

    return 0;
}