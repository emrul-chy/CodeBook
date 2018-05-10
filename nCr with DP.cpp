ll nCr[Max][Max];

ll rec( ll n, ll r ) {
	if( n == r ) {
		return 1;
	}
	if( r == 1 ) {
		return n;
	}
	ll &ret = nCr[n][r];
	if( ~ret ) {
		return ret;
	}
	ret = rec( n-1, r ) + rec( n-1, r-1 );
	return ret;
}
