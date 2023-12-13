#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int N, a[24], ret=INF;
string s;
vector<int> idxV;

void go() {
    int tempRet=0;
    for (int i=0; i<N; ++i) {
        int numH=0, numT=0;
        for (int j=0; j<N; ++j) {
            if (a[j] & (1<<i)) ++numH;
            else ++numT;
        }
        if (numH>=numT) tempRet+=numT;
        else tempRet+=numH;
    }
    ret = min(ret,tempRet);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> s;
        int temp=0;
        for (int j=0; j<N; ++j) {
            if (s[j]=='H') temp += 1<<(N-j-1);
        }
        a[i]=temp;
    }

    for (int i=0; i<(1<<N); ++i) {
        for (int j=0; j<N; ++j) {
            if (i & (1<<j)) a[j]=~a[j], idxV.push_back(j);
        }
        go();
        for (int idx : idxV) a[idx]=~a[idx];
        idxV.clear();
    }

    cout << ret << '\n';

    return 0;
}