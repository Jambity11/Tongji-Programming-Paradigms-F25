#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, t;
	cin >> n >> t;
	auto nums = vector<int>(n + 1, 0);
	for (int i = 0; i < n; i ++) { cin >> nums[i]; }
	long long sum = 0;
	int ans = INT_MAX;
	int l = 0;
	int r = 0;
	auto match = [&](int l, int r) {
		return sum >= t;
	};
	auto insert = [&](int l, int r) {
		sum += nums[r];
	};
	auto remove = [&](int l, int r) {
		sum -= nums[l];
	};
	auto update = [&](int l, int r) {
		if (sum >= t) ans = min(ans, r - l + 2);
	};
	for ( ; l <= n - 1; ) {
		while (l == r || (r <= n - 1 && !match(l, r - 1))) insert(l, r++);
		if (match(l, r - 1)) update(l, r - 2); //mamzule
		else update(l, r - 1); // daotoule  
		remove(l++, r);
	}
	if (ans == INT_MAX) ans = 0;
	cout << ans << endl;
	return 0; 
}