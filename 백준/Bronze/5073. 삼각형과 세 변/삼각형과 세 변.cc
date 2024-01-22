#include <bits/stdc++.h>
using namespace std;  

int x, y, z;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true) {
        cin >> x >> y >> z;
        if (x==0&&y==0&&z==0) break;

        int sum = x + y + z;
        int mx = max(x, max(y, z));
        if (mx < sum-mx) {
            if (x==y&&y==z) cout << "Equilateral" << '\n';
            else if (x==y||y==z||z==x) cout << "Isosceles" << '\n';
            else cout << "Scalene" << '\n';
        }
        else cout << "Invalid" << '\n';
    }

    return 0;
}
