#include <bits/stdc++.h>
using namespace std;

int N, x, y, ret;
struct Line {
    int from, to;
};
vector<Line> v;

bool cmp(const Line& a, const Line& b) {
    if (a.from==b.from) return a.to < b.to;
    return a.from < b.from;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> x >> y;
        Line ln; ln.from = x; ln.to = y;
        v.push_back(ln);
    }

    sort(v.begin(), v.end(), cmp);
    int from = v[0].from, to = v[0].to;
    for (int i=1; i<N; ++i) {
        if (v[i].from<=to && v[i].to>to) to=v[i].to;
        else if (v[i].from > to) {
            ret+=to-from;
            from=v[i].from;
            to=v[i].to;
        }
    }
    ret+=to-from;
    cout << ret << '\n';

    return 0;
}
