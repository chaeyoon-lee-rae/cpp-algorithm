#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
ll x, y;

int main() {
    cin >> x >> y;
    ll a = y * 100;
    ll b = x;
    ll c = (a / b) + 1;

    if (c == 100 || c * b == a || (c * b - a > 0 && 100 - c < 0) || (c * b - a < 0 && 100 - c > 0))
        cout << -1 << "\n";
    else
        cout << ll(ceil(double(c * b - a) / (100 - c))) << "\n";

    return 0;
}
