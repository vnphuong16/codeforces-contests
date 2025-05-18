// @author: PaNda
// @time: 2025-05-17 21:37:18
// It's Time To Duel

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// Code here
	int t; std::cin >> t;

	while (t--) {
		int n; std::cin >> n;
		std::vector<int> vec(n + 1);
		for (int i = 1; i <= n; ++i) {
			std::cin >> vec[i];
		}

		int m = n - 1;
		std::vector<std::vector<int>> imp(m + 1);
		std::vector<std::pair<int, bool>> unit;
		for (int i = 1; i <= n; ++i) {
			if (vec[i] == 0) {
				if (i > 1) {
					unit.emplace_back(i - 1, true);
				}
				if (i < n) {
					unit.emplace_back(i, false);
				}
			}
			else {
				if (i == 1) {
					unit.emplace_back(1, true);
				}
				else if (i == n) {
					unit.emplace_back(n - 1, false);
				}
				else {
					imp[i - 1].push_back(i);
				}
			}
		}

		std::vector<int> assign(m + 1, -1);
		std::deque<std::pair<int, bool>> dq;
		for (auto &u : unit) {
			dq.push_back(u);
		}

		bool fail = false;
		while (!dq.empty() && !fail) {
			auto p = dq.front();
			dq.pop_front();

			int v = p.first;
			bool val = p.second;

			if (assign[v] != -1) {
				if (assign[v] != (val ? 1 : 0)) {
					fail = true;
				}
				continue;
			}

			assign[v] = val ? 1 : 0;
			if (val) {
				for (int t : imp[v]) {
					dq.emplace_back(t, true);
				}
			}
		}
		std::cout << (fail ? "YES\n" : "NO\n");
	}

	return 0;
}