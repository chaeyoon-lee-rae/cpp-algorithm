#include <bits/stdc++.h>
using namespace std;  

int N;
double score;
priority_queue<double> pq;
vector<double> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%lf", &score);
        if (pq.size()==7) {
            pq.push(score); pq.pop();
        } else pq.push(score);
    }

    while (pq.size()) {
        v.push_back(pq.top()); pq.pop();
    }
    reverse(v.begin(),v.end());
    for (double val:v) printf("%.3lf\n", val);

    return 0;
}
