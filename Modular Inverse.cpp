pll extendedEuclid(ll a, ll b) { // returns x, y | ax + by = gcd(a,b)
	if(b == 0) return pll(1LL, 0LL);
	else {
		pll d = extendedEuclid(b, a % b);
		return pll(d.second, d.first - d.second * (a / b));
	}
}

ll modularInverse(ll a, ll n) {
	pair<ll, ll> ret = extendedEuclid(a, n);
	return ((ret.first % n) + n) % n;
}
