#include <bits/stdc++.h>
using namespace std;  

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i=0; i<pow(10,4); i++) {
        string s = "000" + to_string(i);
        string a = s.substr(s.size()-4, 4);
        for (int j=0; j<=4; j++) {
            string temp = a.substr(0, 4-j) + "666" + a.substr(4-j,j);
            v.push_back(stoi(temp));
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v[N-1] << '\n';

    return 0;
}