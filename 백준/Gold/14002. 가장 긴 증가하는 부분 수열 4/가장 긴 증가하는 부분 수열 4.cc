#include <bits/stdc++.h>
using namespace std;  

int n, x, y, len=1, idx, a[1001], prev_list[1001], cnt[1001];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }

    fill(prev_list, prev_list+n, -1);
    fill(cnt, cnt+n, 1);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<i; ++j) {
            if (a[j]<a[i]&&cnt[i]<cnt[j]+1) {
                cnt[i]=cnt[j]+1;
                prev_list[i]=j;
                if (len<cnt[i]) {
                    len=cnt[i];
                    idx=i;
                }
            }
        }
    }
    
    cout << len << '\n';
    for (int i=idx; i!=-1; i=prev_list[i]) {
        v.push_back(a[i]);
    }
    for (auto it=v.rbegin(); it!=v.rend(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}
