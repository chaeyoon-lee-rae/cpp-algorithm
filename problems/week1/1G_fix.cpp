#include <bits/stdc++.h>
using namespace std;  

int N;
string s, start, last, temp;

bool comp(string &temp) {
    if (start.size()+last.size()<=temp.size()) {
        return temp.substr(0,start.size())==start&&temp.substr(temp.size()-last.size())==last;
    } else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> s;
    int idx = s.find('*');
    start = s.substr(0,idx);
    last = s.substr(idx+1);
    for (int i=0; i<N; ++i) {
        cin >> temp;
        cout << (comp(temp)?"DA":"NE") << '\n';
    }
    
    return 0;
}
