#include <bits/stdc++.h>
using namespace std;  

int a, ret, visited[7];
bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<3; ++i) {
        cin >> a;
        visited[a]+=1;
    }
    for (int i=1; i<=6; ++i) {
        if (visited[i]==3) {
            cout << 10000+i*1000 << '\n';
            break;
        }
        if (visited[i]==2) {
            flag=1;
            cout << 1000+i*100 << '\n';
            break;
        }
        if (visited[i]==1) {
            ret = max(ret, i);
        }
    }
    if (!flag && ret) cout << ret*100 << '\n';

    return 0;
}