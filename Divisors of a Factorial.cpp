#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

vector <ull> vec;

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

        for (int p = 2; p < MAX; p++) {
                if ( isPrime[p] ) {
                        vec.push_back(p);
                }
        }
}

ull factorialDivisors(ull n) {
        ull res = 1;

        for ( ull x : vec ) {
                ull p = x;

                ull exp = 0;
                while (p <= n) {
                        exp = exp + (n / p);
                        p = p * x;
                }
                res = res * (exp + 1);
        }

        return res;
}

int main()
{
        sieve();
        cout << factorialDivisors(6) << endl;
        return 0;
}
