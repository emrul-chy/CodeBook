#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

const int Max = 2e6 + 10;
const int Mod = 1e9 + 7;
const ll Inf = 1LL << 62;

int Z[Max];
char S[Max];

void compute_z_function(int n) {
	int L, R, k;
	L = R = 0;
	for(int i = 1; i < n; ++i) {
		if(i > R) {
			L = R = i;
			while(R < n && S[R - L] == S[R]) {
				R++;
			}
			Z[i] = R - L;
			R--;
		}
		else {
			k = i - L;
			if(Z[k] < R - i + 1) {
				Z[i] = Z[k];
			}
			else {
				L = i;
				while(R < n && S[R - L] == S[R]) {
					R++;
				}
				Z[i] = R - L;
				R--;
			}
		}
	}
}

int main() {
	scanf("%s", S);
	compute_z_function(strlen(S));

	for(int i = 0; i < strlen(S); i++) {
		printf("%d ", Z[i]);
	}
	return 0;
}
