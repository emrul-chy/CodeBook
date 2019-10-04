ll f[Max], inv[Max];

ll BigMod(ll a, int e) {
	if(e == -1) e = Mod - 2;
	ll r = 1;
	while(e) {
		if(e & 1) r *= a, r %= Mod;
		a *= a, a %= Mod, e >>= 1;
	}
	return r;
}

ll nCr(int x, int y) {
	if(x < 0 or y < 0 or x < y) return 0;
	return f[x] * (inv[y] * inv[x - y] % Mod) % Mod;
}

void init() {
	f[0] = 1;
	for(int i = 1; i < Max; ++i) {
		f[i] = i * 1LL * f[i - 1] % Mod;
	}
	inv[Max - 1] = BigMod(f[Max - 1], -1);
	for(int i = Max - 1; i; --i) {
		inv[i - 1] = i * 1LL * inv[i] % Mod;
	}
}
