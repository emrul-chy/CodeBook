#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

ll f[Max], inv[Max];

ll BigMod(ll a, int e) {
	if (e == -1) e = Mod - 2;
	ll r = 1;
	while (e) {
		if (e & 1) r *= a, r %= Mod;
		a *= a, a %= Mod, e >>= 1;
	}
	return r;
}

ll nCr( int x, int y) {
	if (x < 0 or y < 0 or x < y) return 0;
	return f[x] * (inv[y] * inv[x - y] % Mod) % Mod;
}

int main() {
	f[0] = 1;
	for (int i = 1; i < Max; ++i) {
		f[i] = i * 1LL * f[i - 1] % Mod;
	}
	inv[Max - 1] = BigMod(f[Max - 1], -1);
	for (int i = Max - 1; i; --i) {
		inv[i - 1] = i * 1LL * inv[i] % Mod;
	}
	printf("%lld\n", nCr( 12, 2 ));
	return 0;
}
