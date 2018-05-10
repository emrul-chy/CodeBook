bool isPrime[1000101];

void sieve() {
        int MAX = 1000100, sq = sqrt(MAX);
        memset(isPrime, true, sizeof isPrime);
        for( int i=4; i<=MAX; i+=2) {
                isPrime[i] = 0;
        }
        for( int i=3; i<=sq; i+=2 ) {
                if( isPrime[i] ) {
                        for( int j=i*i; j<=MAX; j+=i ){
                                isPrime[j] = 0;
                        }
                }
        }
        isPrime[1] = 0;
        isPrime[0] = 0;
}
