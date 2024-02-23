#include <bits/stdc++.h>
using namespace std;  

int n, k, cnt, a[101];
bool vis[101];
const int INF=1e4;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<k; ++i) {
        cin >> a[i];
    }
    for (int i=0; i<k; ++i) {
        if (!vis[a[i]]) {
            if (v.size()==n) {
                int last_idx=0, last_val, erase_idx;
                for (int e=0; e<n; ++e) {
                    int here=INF;
                    for (int j=i+1; j<k; ++j) {
                        if (v[e]==a[j]) {
                            here=j; break;
                        }
                    }
                    if (last_idx<here) {
                        last_idx=here;
                        last_val=v[e];
                        erase_idx = e;
                    }
                }    
                vis[last_val]=0;
                v.erase(v.begin()+erase_idx);
                ++cnt; 
            }
            v.push_back(a[i]);
            vis[a[i]]=1;
        }
    }
    cout << cnt << '\n';

    return 0;
}
