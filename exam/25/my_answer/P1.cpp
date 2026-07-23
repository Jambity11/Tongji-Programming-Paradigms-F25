#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// 骗分
// int main() {
// 	cout << 25 << endl;
// 	return 0;
// }


int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int n = s.size();
	int ans = 1;
	auto used = vector<vector<int>>(0, vector<int>(n));
	vector<int> tmp(n);
	auto match = [&](const vector<int>& vec) {
		string ss;
		for (int k = 0; k < n; k++) {
			if (vec[k] == 1) ss += s[k];
		}
		for (int i = 0, j = ss.size() - 1; i <= j; i++, j--) {
			if (ss[i] != ss[j]) return 0;
		}
		return 1;
	};
	auto traceback = [&](auto& self, int loc) {
		if (match(tmp)) used.push_back(tmp);
		if (loc == n) return;

		tmp[loc] = 1;
		self(self, loc + 1);
		tmp[loc] = 0;
		self(self, loc + 1);
	};
	traceback(traceback, 0);
	auto buxiangjiao = [&](int a, int b) {
		vector<int> v1 = used[a], v2 = used[b];
		for(int k = 0; k < n; k++) {
			if (v1[k] && v2[k]) return 0;
		}
		return 1;
	};
	auto count1 = [&](vector<int>& vec) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (vec[i] == 1) cnt++;
		}
		return cnt;
	}; 
	for (int i = 0; i < used.size(); i++) {
		for (int j = i + 1; j < used.size(); j++) {
			if (buxiangjiao(i, j)) ans = max(ans, count1(used[i]) * count1(used[j]));
		}
	}

	cout << ans << endl;
	return 0;
}