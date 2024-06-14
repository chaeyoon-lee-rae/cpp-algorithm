#include <bits/stdc++.h>
using namespace std; 

int a[9];
int total;
pair<int, int> p;

void solve() {
    for (int i=0; i<9; ++i) {
        for (int j=i+1; j<9; ++j) {
            if (total - a[i] - a[j] == 100) {
                p = {i, j};
            }
        }
    }
}

int main() {
    for (int i=0; i<9; ++i) {
        cin >> a[i];
    }

    sort(a, a+9);
    total = accumulate(a, a+9, 0);

    solve();
    
    vector<int> v;
    for (int i=0; i<9; ++i) {
        if (i != p.first && i != p.second) {
            cout << a[i] << '\n';
        }
    }

    return 0;
}