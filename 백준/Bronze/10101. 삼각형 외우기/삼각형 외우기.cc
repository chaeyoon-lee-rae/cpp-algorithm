#include <bits/stdc++.h>
using namespace std;  

int x, y, z;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y >> z;
    if (x==60&&y==60&&z==60) cout << "Equilateral" << '\n';
    else if (x+y+z==180) {
        if (x==y||y==z||z==x) cout << "Isosceles" << '\n';
        else cout << "Scalene" << '\n';
    }
    else cout << "Error" << '\n';

    return 0;
}
