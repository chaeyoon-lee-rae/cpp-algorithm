#include <bits/stdc++.h>
using namespace std;  

int N, di, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    while (N!=-1) {
        vector<int> v;
        for (int i=1; i<N; ++i) {
            if (N%i==0) v.push_back(i);
        }
        if (N == accumulate(v.begin(),v.end(),0)) {
            printf("%d = ", N);
            for (int i=0; i<v.size(); ++i) {
                if (i<v.size()-1) printf("%d + ", v[i]);
                else printf("%d\n", v[i]);
            }
        }
        else printf("%d is NOT perfect.\n", N);
        scanf("%d", &N);
    }
}
