#include <bits/stdc++.h>
using namespace std;  

int n, number_n, ret=-1e9, number[10];
char op[10];

int calc(int op_idx, int a, int b) {
	if (op[op_idx]=='*') return a * b;
	if (op[op_idx]=='+') return a + b;
	if (op[op_idx]=='-') return a - b;
	return 0;
}

void go(int idx, int num) {
	if (idx==number_n-1) {
		ret = max(ret, num);
		return;
	}

	go(idx+1, calc(idx, num, number[idx+1]));
	if (idx+2<=number_n-1) {
		int temp = calc(idx+1, number[idx+1], number[idx+2]);
		go(idx+2, calc(idx, num, temp));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n; char ch;
	for (int i=0; i<n; ++i) {
		cin >> ch;
		if (i%2) op[i/2] = ch;
		else number[i/2] = ch - '0';
	}

	number_n = n/2 + 1;

	go(0, number[0]);
	cout << ret << '\n';

	return 0;
}
