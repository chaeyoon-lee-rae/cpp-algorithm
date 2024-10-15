#include <iostream>
#include <limits>
using namespace std;

typedef long long ll;
struct room { ll t, a, h; } rm[123457];
int n;
ll atk_i, ret;

bool check(ll hp_max) {
    ll hp = hp_max;
    ll atk = atk_i;
    for (int i = 0; i < n; ++i) {
        if (rm[i].t == 1) {
            const ll& mon_atk = rm[i].a;
            ll mon_hp = rm[i].h;

            ll num_round = mon_hp / atk;
            if (mon_hp % atk) ++num_round;
            if (hp - mon_atk * (num_round - 1) <= 0) return false;
            else hp -= mon_atk * (num_round - 1);
        }
        else {
            const ll& atk_plus = rm[i].a;
            const ll& hp_plus = rm[i].h;

            hp = min(hp + hp_plus, hp_max);
            atk += atk_plus;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> atk_i;
    for (int i = 0; i < n; ++i)
        cin >> rm[i].t >> rm[i].a >> rm[i].h;

    ll lo = 1, hi = numeric_limits<ll>::max();
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            ret = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << ret << "\n";

    return 0;
}
