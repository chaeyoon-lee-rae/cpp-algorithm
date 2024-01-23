#include <bits/stdc++.h>
using namespace std;  

int N, M, ret;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    for (int i=0; i<N-2; ++i) {
        for (int j=i+1; j<N-1; ++j) {
            for (int k=j+1; k<N; ++k) {
                int sum = v[i]+v[j]+v[k];
                if (sum<=M) ret = max(sum, ret);
            }
        }
    }

    cout << ret << '\n';

    return 0;
}