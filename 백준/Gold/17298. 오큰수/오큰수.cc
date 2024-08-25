#include <bits/stdc++.h>
using namespace std;  

stack<pair<int,int>> stk;
int a[1000001], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(a, -1, sizeof(a));

	cin >> n; int temp;
	for (int i=0; i<n; ++i) {
		cin >> temp;
		while (stk.size() && stk.top().second < temp) {
			a[stk.top().first] = temp;
			stk.pop();
		} 
		stk.push({i, temp});
	}

	for (int i=0; i<n; ++i)
		cout << a[i] << " ";
		
	return 0;
}
