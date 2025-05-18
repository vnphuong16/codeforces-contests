// @author: PaNda
// @time: 2025-05-17 21:59:06

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

long long calculator(long long val) {
	if (val <= 1) {
		return 0;
	}
	return 64 - __builtin_clzll(val - 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// Code here
	int t; std::cin >> t;

	while (t--) {
		int n, a;
		long long m, b;
		std::cin >> n >> m >> a >> b;

		long long da = std::min(a, n - a + 1);
		long long db = std::min(b, m - b + 1);
		long long ch = 1 + calculator(m) + calculator(da);
		long long cv = 1 + calculator(n) + calculator(db);
		
		std::cout << std::min(ch, cv) << "\n";
	}

	return 0;
}