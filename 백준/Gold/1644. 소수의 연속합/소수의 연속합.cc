#include <bits/stdc++.h>
using namespace std;  

const int mx=4000001;
int N, cnt, sum, l, r; bool a[mx];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(a,a+mx,true);
    cin >> N;
    for (int i=2; i*i<=N; ++i) {
        if(a[i]) {
            for (int j=i*i; j<=N; j+=i) {
                a[j]=false;
            }
        }
    }
    for (int i=2; i<=N; ++i) {
        if (a[i]) v.push_back(i);
    }

    while(true) {
        if (sum>=N) sum-=v[l++];
        else if (r==v.size()) break;
        else sum+=v[r++];
        if (sum==N) ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}
