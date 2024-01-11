#include <bits/stdc++.h>
using namespace std;  

int N, M, temp1, temp2;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i=1; i<=N; ++i) v.push_back(i);
    for (int i=0; i<M; ++i) {
        cin >> temp1 >> temp2;
        --temp1; --temp2;
        reverse(v.begin()+temp1, v.begin()+temp2+1);
    }
    for (int val:v) cout << val << ' ';

    return 0;
}