ll divcnt[Max];

void DivisorCount( ll n ) {
	for( int i=1; i<=n; i++ ) {
		for( int j=i; j<=n; j+=i ) {
			divcnt[j]++;
		}
	}
}
