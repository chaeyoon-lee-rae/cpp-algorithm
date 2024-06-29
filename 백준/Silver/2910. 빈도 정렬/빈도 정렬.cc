#include <bits/stdc++.h>
using namespace std;  

int N, C, temp;
vector<pair<int, int>> v;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;
    for (int i=0; i<N; i++) {
        cin >> temp;

        bool f = false;
        for (auto &it : v) {
            if (it.first == temp) {
                it.second += 1;
                f = true;
                break;
            }
        }
        if (!f) v.push_back({temp, 1});
    }

    stable_sort(v.begin(), v.end(), cmp);

    for (auto &it : v) {
        for (int i=0; i < it.second; i++) {
            cout << it.first << " ";
        }
    }

    return 0;
}