#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
ll n, atk, t, a, h, h_plus, mx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> atk;
    for (int i = 0; i < n; ++i) {
        cin >> t >> a >> h;
        if (t == 1) {
            ll damage = a * ll(ceil(double(h) / atk) - 1);
            if (h_plus < damage) {
                mx += damage - h_plus;
                h_plus = 0;
            }
            else 
                h_plus -= damage;
        }
        else {
            atk += a;
            h_plus = min(h_plus + h, mx);
        }
    }

    cout << mx + 1 << "\n";

    return 0;
}
