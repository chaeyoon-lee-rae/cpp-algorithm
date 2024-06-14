#include <bits/stdc++.h>
using namespace std;  

const int sz = 9, n=7;
int a[10];

void comb(int idx, int sum, vector<int>& v) {
    if (v.size()==n) {
        if (sum==100) {
            sort(v.begin(), v.end());
            for (auto& e:v) cout << e << endl;
            exit(0);
        }
    } 
    for (int i=idx+1; i<sz; ++i) {
        v.push_back(a[i]);
        comb(i, sum+a[i], v);
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<sz; ++i) cin >> a[i];

    vector<int> v;
    comb(-1,0,v);

    return 0;
}
