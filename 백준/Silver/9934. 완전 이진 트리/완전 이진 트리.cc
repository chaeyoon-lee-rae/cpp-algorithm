#include <bits/stdc++.h>
using namespace std;  

int K, a[1025];
vector<int> v[11];

void go(int from, int to, int level) {
    if (from > to) return;
    if (from==to) {v[level].push_back(a[from]); return;}
    
    int mid=(from+to)/2;
    v[level].push_back(a[mid]);
    go(from, mid-1, level+1);
    go(mid+1, to, level+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for (int i=0; i<pow(2,K)-1; ++i) {
        cin >> a[i];
    }

    go(0,pow(2,K)-1,0);
    for (int i=0; i<K; ++i) {
        for (int it:v[i]) cout << it << " ";
        cout << '\n';
    }

    return 0;
}