#include <bits/stdc++.h>
using namespace std;  

int a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;
    if (a < 60) cout << 'F' << '\n';
    else if (a < 70) cout << 'D' << '\n';
    else if (a < 80) cout << 'C' << '\n';
    else if (a < 90) cout << 'B' << '\n';
    else cout << 'A' << '\n';

    return 0;
}