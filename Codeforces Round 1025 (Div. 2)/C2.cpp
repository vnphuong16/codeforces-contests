// @author: PaNda
// @time: 2025-05-17 22:07:14

#include <iostream>
#include <string>
#include <iomanip>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// Code here
	int t; std::cin >> t;
	while (t--) {
		long long n; std::cin >> n;
		std::string str;
		std::cout << "mul 9\n";
		std::cout.flush();
		std::cin >> str;
		if (str == "-1") {
			continue;
		}

		std::cout << "digit\n";
		std::cout.flush();
		std::cin >> str;
		if (str == "-1") {
			continue;
		}

		std::cout << "digit\n";
		std::cout.flush();
		std::cin >> str;
		if (str == "-1") {
			continue;
		}

		std::cout << "add " << (n - 9) << "\n";
		std::cout.flush();
		std::cin >> str;
		if (str == "-1") {
			continue;
		}

		std::cout << "!\n";
		std::cout.flush();
		std::cin >> str;
		if (str == "-1") {
			continue;
		}
	}

	return 0;
}