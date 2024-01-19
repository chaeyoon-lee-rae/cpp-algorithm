#include <bits/stdc++.h>
using namespace std;  

int N, money;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> money;
        for (int cent:{25,10,5,1}) {
            cout << money / cent << ' ';
            money %= cent;
        }
        cout << '\n';
    }

    return 0;
}