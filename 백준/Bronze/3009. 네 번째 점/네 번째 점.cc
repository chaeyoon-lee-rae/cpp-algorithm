#include <bits/stdc++.h>
using namespace std;  

int x[4],y[4], a, b, retx, rety;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=0; i<3; ++i) {
        cin >> a >> b;
        x[i]=a; y[i]=b;
    }
    if (x[0]==x[1]) retx=x[2];
    else if (x[0]==x[2]) retx=x[1];
    else retx = x[0];

    if (y[0]==y[1]) rety=y[2];
    else if (y[0]==y[2]) rety=y[1];
    else rety = y[0];

    cout << retx << ' ' << rety << '\n';

    return 0;
}
