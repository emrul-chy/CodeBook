/*
        String Hashing
*/
typedef long long int ll;
typedef pair <ll, ll> pll;
const int base = 331;

const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

ll pw[Max];
ll Hash[Max];

void pre_power() {
	pw[0] = 1;
	for(int i = 1; i < Max; i++) {
		pw[i] = (pw[i - 1] * base) % Mod;
	}
}

void Hashing(string str, int len) {
	ll hash_val = 0;
	for(int i = 0; i < len; i++) {
		hash_val = (hash_val * base + str[i]) % Mod;
		Hash[i + 1] = hash_val;
	}
}

ll SubstringHash(int l, int r) {
	return (Hash[r] - (Hash[l - 1] * pw[r - l + 1]) % Mod + Mod) % Mod;
}
