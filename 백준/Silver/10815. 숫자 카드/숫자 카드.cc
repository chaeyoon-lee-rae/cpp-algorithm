#include <bits/stdc++.h>
using namespace std;  

map<int, int> mp;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        mp.insert({temp,1});
    }
    cin >> M;
    for (int i=0; i<M; ++i) {
        int temp; cin >> temp;
        cout << (mp[temp]==0 ? 0 : 1) << ' '; 
    }

    return 0;
}
