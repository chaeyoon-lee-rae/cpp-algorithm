#include <bits/stdc++.h>
using namespace std;  

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int i=2;
    while (N>1) {
        if (N%i==0) {
            cout << i << '\n';
            N/=i;
        }
        else ++i;
    }

    return 0;
}
