#include <bits/stdc++.h>
using namespace std;  

int price[4], cnt[101], arr_t, dep_t, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=1; i<=3; ++i) 
        cin >> price[i];

    for (int i=0; i<3; ++i) {
        cin >> arr_t >> dep_t;
        for (int j=arr_t; j<dep_t; ++j)
            ++cnt[j];
    }

    for (int i=1; i<=100; ++i)
        ret+=cnt[i]*price[cnt[i]];

    cout << ret << '\n';

    return 0;
}
