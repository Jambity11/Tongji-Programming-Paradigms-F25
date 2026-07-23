#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;



int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = s.size();
	int ans = 1;
	auto same= vector<vector<int>>(n, vector<int>());
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= i; j--) {
			if (s[i] == s[j]) {
				same[i].push_back(j);
			}
		}
	}
	// 2
	int len1 = 0;

	for (int hd = 0; hd < n; hd++) {
		vector<int> used1(n);
		for (int l = hd, r = same[hd][0]; l <= r; ) {
			if (s[l] == s[r]) {
				len1++;
				if (l != r) len1++;
				used1[l] = 1;
				used1[r] = 1;
			}
			l++;
			for (int i = 0; i < same[l].size(); i++) {
				if (same[l][i] <)
			}
		}
	}

	return 0;
}