ll C[Max][Max];

ll nCr(ll n, ll r) {
	if(n == r) {
		return 1;
	}
	if(r == 1) {
		return n;
	}
	ll &ret = C[n][r];
	if(~ret) {
		return ret;
	}
	ret = nCr(n - 1, r) + nCr(n - 1, r - 1);
	return ret;
}
