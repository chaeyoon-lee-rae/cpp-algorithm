#include <bits/stdc++.h>
using namespace std;  

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    N /= 4;
    for (int i=0; i<N; ++i) {
        cout << "long" << " ";
    }
    cout << "int" << '\n';

    return 0;
}