#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

#define int long long

const int MOD = 998244353;
const int MAX = 501;

int fac[MAX], invFac[MAX];

int power(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int inverse(int a) {
    return power(a, MOD - 2);
}

int comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * invFac[k] % MOD * invFac[n - k] % MOD;
}

void precompute() {
    fac[0] = invFac[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
        invFac[i] = inverse(fac[i]);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> dp(k + 1);
        dp[0] = 1;

        for (int i = n - 1; i >= 0; --i) {
            vector<int> next(k + 1, 0);
            for (int len = 0; len <= k; ++len) {
                if (!dp[len]) continue;
                for (int cnt = 0; len + cnt <= k; ++cnt) {
                    int T = len + cnt;
                    int even = (T + 1) / 2;
                    int odd = T / 2;
                    int digit = s[i] - '0';
                    int pos = (digit == 0) ? even : odd;
                    int ways = comb(pos, cnt);
                    next[T] = (next[T] + dp[len] * ways % MOD) % MOD;
                }
            }
            dp = next;
        }

        cout << dp[k] << '\n';
    }

    return 0;
}
