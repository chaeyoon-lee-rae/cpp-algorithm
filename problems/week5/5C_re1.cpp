#include <bits/stdc++.h>
using namespace std;  

int N, ret;
pair<int,int> a[200001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    sort(a, a+N);
    for (int i=0; i<N; ++i) {
        pq.push(a[i].second);
        if (pq.size()>a[i].first) pq.pop();
    }
    while(pq.size()) {
        ret+=pq.top(); pq.pop();
    }
    printf("%d\n", ret);

    return 0;
}
