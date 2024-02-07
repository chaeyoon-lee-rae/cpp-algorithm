#include <bits/stdc++.h>
using namespace std;  

int N, M;

int calc(vector<int> &v, int &temp) {
    return (upper_bound(v.begin(),v.end(),temp) - lower_bound(v.begin(),v.end(),temp));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> v(N);
    for (int i=0; i<N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i=0; i<M; ++i) {
        int temp; cin >> temp;
        cout << calc(v, temp) << ' ';
    }

    return 0;
}
