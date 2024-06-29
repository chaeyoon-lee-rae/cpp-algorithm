#include <bits/stdc++.h>
using namespace std;  

int n; bool a[65][65];
string temp;

bool check(int y, int x, const int& len, bool first) {
    for (int i=y; i<y+len; ++i)
        for (int j=x; j<x+len; ++j)
            if (a[i][j]!=first) return false;
    return true;
}

string go(int y, int x, const int& len, bool first) {
    string s="";
    if (check(y,x,len,first)||len==1) 
        s = (first ? "1" : "0");
    else {
        s+="(";
        s+=go(y,x,len/2,a[y][x]);
        s+=go(y,x+len/2,len/2,a[y][x+len/2]);
        s+=go(y+len/2,x,len/2,a[y+len/2][x]);
        s+=go(y+len/2,x+len/2,len/2,a[y+len/2][x+len/2]);
        s+=")";
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> temp;
        for (int j=0; j<n; ++j)
            a[i][j]=temp[j]-'0';
    }
    cout << go(0,0,n,a[0][0]) << '\n';
    
    return 0;
}
