bool isPrime[1000101];

void sieve() {
	int lim = 1000100, sq = sqrt(lim);
	memset(isPrime, true, sizeof isPrime);
	for(int i = 4; i <= lim; i += 2) {
		isPrime[i] = 0;
	}
	for(int i = 3; i <= sq; i += 2) {
		if(isPrime[i]) {
			for(int j = i * i; j <= lim; j += i) {
				isPrime[j] = 0;
			}
		}
	}
	isPrime[1] = 0;
	isPrime[0] = 0;
}
